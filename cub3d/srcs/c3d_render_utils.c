/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:26:35 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 18:00:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ft_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

bool	ft_touch(float px, float py, t_cub3d *cub)
{
	int	x;
	int	y;

	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (x < 0 || y < 0)
		return (true);
	return (cub->map[y][x] == '1');
}

bool	ft_in_limit(float x, float y, t_cub3d *cub)
{
	if (!ft_touch(x + 1, y, cub) && !ft_touch(x, y + 1, cub)
		&& !ft_touch(x - 1, y, cub) && !ft_touch(x, y - 1, cub))
		return (true);
	return (false);
}

void	ft_put_pixel(int x, int y, int color, t_cub3d *cub)
{
	int	offset;

	offset = (cub->size_line * y) + (x * (cub->bpp / 8));
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	cub->data[offset] = color & 0xFF;
	cub->data[offset + 1] = (color >> 8) & 0xFF;
	cub->data[offset + 2] = (color >> 16) & 0xFF;
}
