/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_2d_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:29:56 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/26 14:56:47 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_bresenham(t_bresenham *b, t_point start, t_point end)
{
	b->x = (int)start.x;
	b->y = (int)start.y;
	b->dx = abs((int)end.x - b->x);
	if (b->x < (int)end.x)
		b->sx = 1;
	else
		b->sx = -1;
	b->dy = -abs((int)end.y - b->y);
	if (b->y < (int)end.y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx + b->dy;
	b->e2 = 0;
}

void	ft_draw_line_2d(t_cub3d *cub, t_point start, t_point end, int color)
{
	t_bresenham	b;

	ft_init_bresenham(&b, start, end);
	while (1)
	{
		ft_put_pixel(b.x, b.y, color, cub);
		if (b.x == (int)end.x && b.y == (int)end.y)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 >= b.dy)
		{
			b.err += b.dy;
			b.x += b.sx;
		}
		if (b.e2 <= b.dx)
		{
			b.err += b.dx;
			b.y += b.sy;
		}
	}
}

void	ft_draw_rays_2d(t_cub3d *cub)
{
	float	angle;
	t_point	start;
	t_point	end;
	float	distance;
	int		i;

	start.x = cub->player.x;
	start.y = cub->player.y;
	i = 0;
	while (i < WIDTH)
	{
		angle = cub->player.angle - FOV / 2 + i * FOV / WIDTH;
		distance = ft_cast_ray_3d(cub->player.x, cub->player.y, angle, cub);
		end.x = cub->player.x + cos(angle) * distance;
		end.y = cub->player.y + sin(angle) * distance;
		ft_draw_line_2d(cub, start, end, YELL_PIXEL);
		i++;
	}
}
