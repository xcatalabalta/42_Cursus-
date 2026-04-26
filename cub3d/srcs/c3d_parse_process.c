/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:25:13 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/23 09:44:42 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*make_arg(char **line)
{
	char	*tmp;

	replace_chars(line, '\t', ' ');
	replace_chars(line, '\n', '\0');
	clean_redundant_spaces(line);
	tmp = ft_strtrim(*line, " ");
	free(*line);
	*line = tmp;
	return (*line);
}

static char	*make_map(t_cub3d *cub, char **line)
{
	replace_tabs(cub, line);
	replace_chars(line, ' ', '0');
	replace_chars(line, '\n', '\0');
	return (*line);
}

static int	line_process(t_cub3d *cub, char *line)
{
	if (!ft_strncmp(line, "EA ", 3))
		cub->east_i = 1;
	else if (!ft_strncmp(line, "SO ", 3) && !cub->south)
		cub->south_i = 1;
	else if (!ft_strncmp(line, "WE ", 3) && !cub->west)
		cub->west_i = 1;
	else if (!ft_strncmp(line, "NO ", 3) && !cub->north)
		cub->north_i = 1;
	else if (!ft_strncmp(line, "C ", 2))
		cub->ceiling_i = 1;
	else if (!ft_strncmp(line, "F ", 2))
		cub->floor_i = 1;
	else if (valid_chars(cub, line, " 01ESWN"))
		error_exit(cub, "Map starts befor config is complete.");
	else
		return (0);
	return (1);
}

int	map_process(t_cub3d *cub, int i)
{
	if (!push_line_to(cub, make_map(cub, &cub->read[i]), &cub->raw_map))
		error_exit(cub, "Malloc error (map_process).");
	return (1);
}

int	read_process(t_cub3d *cub)
{
	int	in_map;
	int	tab_len;
	int	i;

	in_map = 0;
	tab_len = ft_tablen(cub->read);
	i = -1;
	while (++i < tab_len)
	{
		if (!in_map)
		{
			if (line_process(cub, make_arg(&cub->read[i])))
				push_line_to(cub, make_arg(&cub->read[i]), &cub->raw_args);
			if (all_config_assigned(cub, in_map))
				in_map = 1;
		}
		else if (in_map && !all_config_assigned(cub, in_map))
			return (set_error(cub, "Missing configuration before map."));
		else if (!map_process(cub, i))
			return (set_error(cub, "Cannot procees map."));
	}
	normalize_map_width(cub);
	return (1);
}
