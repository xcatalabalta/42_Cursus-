/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:13:36 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 14:04:47 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	out_of_map(t_cub3d *cub, int x, int y)
{
	if (x < 0 || y < 0 || x > cub->mw - 1 || y > cub->mh - 1)
		return (!(set_error(cub, "Map not closed.")));
	return (0);
}

int	get_tab_w_h_o(char **tab, int *w, int *h)
{
	int	j;

	while (tab[*h])
	{
		j = 0;
		while (tab[*h][j])
			j++;
		if (j > *w)
			*w = j;
		(*h)++;
	}
	return (1);
}

void	normalize_map_width(t_cub3d *cub)
{
	int		i;
	int		len;
	char	*new_line;

	get_tab_w_h_o(cub->raw_map, &cub->mw, &cub->mh);
	i = 0;
	while (cub->raw_map[i])
	{
		len = ft_strlen(cub->raw_map[i]);
		if (len < cub->mw)
		{
			new_line = ft_calloc(cub->mw + 1, sizeof(char));
			if (!new_line)
				error_exit(cub, "Malloc failed (normalize_map_width).");
			ft_memcpy(new_line, cub->raw_map[i], len);
			while (len < cub->mw)
				new_line[len++] = '0';
			new_line[len] = '\0';
			free(cub->raw_map[i]);
			cub->raw_map[i] = new_line;
		}
		i++;
	}
}

int	one_player(t_cub3d *cub, char **map)
{
	int	count;
	int	j;
	int	i;
	int	len;

	count = 0;
	j = 0;
	i = -1;
	len = ft_strlen(map[j]);
	while (xy_iterator(&j, cub->mh, &i, len))
	{
		if (ft_strchr("ESWN", map[j][i]))
		{
			cub->px = i;
			cub->py = j;
			cub->po = map[j][i];
			count++;
		}
		len = ft_strlen(map[j]);
	}
	if (count != 1)
		return (set_error(cub, "Number of players is different than one."));
	return (1);
}

int	validate_map(t_cub3d *cub)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	if (cub->raw_map && cub->raw_map[0])
		len = ft_strlen(cub->raw_map[0]);
	else
		return (set_error(cub, "No map."));
	i = -1;
	j = 0;
	while (xy_iterator(&j, cub->mh, &i, len))
	{
		if (!ft_strchr("\t 01ESWN", cub->raw_map[j][i]))
			return (set_error(cub, "Invalid char in map."));
		len = ft_strlen(cub->raw_map[j]);
	}
	if (!one_player(cub, cub->raw_map))
		return (set_error(cub, "Wrong map desing, number of players."));
	if (!map_closed(cub, cub->raw_map))
		return (set_error(cub, "Wrong map desing, not closed."));
	cub->map = cub->raw_map;
	cub->raw_map = NULL;
	return (1);
}
