/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_logic_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:44:55 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/25 17:19:29 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	xy_iterator(int *y_s, int y_e, int *x_s, int x_e)
{
	(*x_s)++;
	if (!y_s)
		return (*x_s < x_e);
	if (*x_s >= x_e)
	{
		*x_s = 0;
		(*y_s)++;
	}
	return (*y_s < y_e);
}

int	all_config_assigned(t_cub3d *cub, int in_map)
{
	if ((cub->north_i && cub->south_i && cub->west_i && cub->east_i
			&& cub->floor_i && cub->ceiling_i) && !in_map)
	{
		printf("All configuration params set.\n");
		printf("Starting to parse map....\n");
	}
	return (cub->north_i && cub->south_i && cub->west_i && cub->east_i
		&& cub->floor_i && cub->ceiling_i);
}

int	valid_chars(t_cub3d *cub, char *line, char *allowed_chars)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = -1;
	while (++i < len)
	{
		if (line && ft_strchr(allowed_chars, line[i]) == NULL)
			return (set_error(cub, "Invalid char in sequence."));
	}
	return (1);
}

float	ft_tern(float base, float compare, float if_true, float if_false)
{
	if (base == compare)
		return (if_true);
	return (if_false);
}
