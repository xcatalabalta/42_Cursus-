/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:37:49 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 12:00:31 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_texture(t_cub3d *cub, char **dest, char *line)
{
	int	fd;
	int	i;

	if (*dest)
		return (set_error(cub, "Duplicated texture path."));
	if (ft_strlen(line) == 0)
		return (set_error(cub, "No path found."));
	i = 0;
	while (line && line[i])
	{
		if (!ft_isalnum(line[i]) && !ft_strchr("./_-", line[i]))
			error_exit(cub, "Invalid character in texture pathname.");
		i++;
	}
	fd = open(line, O_RDONLY);
	if (fd < 0)
		error_exit(cub, "Invalid texture pathname.");
	close(fd);
	*dest = ft_strdup(line);
	if (!*dest)
		error_exit(cub, "Malloc error (process_texture).");
	return (1);
}

int	texture_process(t_cub3d *cub, char *line)
{
	int	res;

	if (line[0] == 'E')
		res = validate_texture(cub, &cub->east, line + 3);
	else if (line[0] == 'S')
		res = validate_texture(cub, &cub->south, line + 3);
	else if (line[0] == 'W')
		res = validate_texture(cub, &cub->west, line + 3);
	else if (line[0] == 'N')
		res = validate_texture(cub, &cub->north, line + 3);
	else if (line[0] == 'C' || line[0] == 'F')
		res = 1;
	else
		return (set_error(cub, "Invalid texture arg found after parsing."));
	return (res);
}
