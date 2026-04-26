/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:46:40 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/27 15:54:25 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	extract_rgb(t_cub3d *cub, int *dest, char *line, int j)
{
	int		val;

	val = ft_atoi(line);
	if (val < 0 || val > 255)
		return (set_error(cub, "Some rgb value is out of range"));
	dest[j] = val;
	return (1);
}

static char	**split_and_trim(t_cub3d *cub, char ***tmp, char *line)
{
	char	*aux;
	int		i;

	*tmp = ft_split(line, ',');
	if (!*tmp)
		error_exit(cub, "Malloc error (process_rgb).");
	if (ft_tablen(*tmp) != 3)
		error_exit(cub, "Wrong number of rgb values");
	i = 0;
	while (i < 3)
	{
		aux = ft_strtrim((*tmp)[i], " \t");
		free((*tmp)[i]);
		(*tmp)[i] = aux;
		i++;
	}
	return (*tmp);
}

static int	validate_rgb(t_cub3d *cub, int *dest, char *line)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 0;
	if (!split_and_trim(cub, &tmp, line))
		error_exit(cub, "Rgb error.");
	while (xy_iterator(&j, 3, &i, ft_strlen(tmp[j])))
	{
		if (!ft_isdigit(tmp[j][i]))
			error_exit(cub, "Some rgb param is not a digit.");
		if (!extract_rgb(cub, dest, tmp[j], j))
			return (set_error(cub, "Cannot extract rgb value"));
	}
	free_tab(&tmp);
	return (1);
}

int	rgb_process(t_cub3d *cub, char *line)
{
	int	res;

	if (line[0] == 'E' || line[0] == 'S' || line[0] == 'W' || line[0] == 'N')
		res = 1;
	else if (line[0] == 'C')
		res = validate_rgb(cub, cub->ceiling, line + 2);
	else if (line[0] == 'F')
		res = validate_rgb(cub, cub->floor, line + 2);
	else
		return (set_error(cub, "Invalid texture arg found after parsing."));
	return (res);
}
