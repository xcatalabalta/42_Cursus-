/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_3d_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:34:31 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/01 07:44:51 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_texture(t_cub3d *cub, float a)
{
	if (cub->side == 0)
	{
		if (cosf(a) > 0)
			cub->t_put = &cub->tex_e;
		else
			cub->t_put = &cub->tex_w;
	}
	else
	{
		if (sinf(a) > 0)
			cub->t_put = &cub->tex_s;
		else
			cub->t_put = &cub->tex_n;
	}
}

void	ft_draw_line_3d(t_player *p, t_cub3d *cub, float a, int col)
{
	float	dist;
	int		wall_height;
	int		line_start;
	int		line_end;
	int		y;

	cub->player.ray_angle = a;
	dist = ft_cast_ray_3d(p->x, p->y, a, cub);
	dist *= cosf(a - p->angle);
	wall_height = (BLOCK * HEIGHT) / (dist * 2 * tan(FOV / 2));
	line_start = (HEIGHT / 2) - (int)(wall_height / 2);
	line_end = (HEIGHT / 2) + (int)(wall_height / 2);
	if (line_end >= HEIGHT)
		line_end = HEIGHT - 1;
	if (line_start < 0)
		line_start = 0;
	set_texture(cub, a);
	y = line_start;
	while (y < line_end)
	{
		ft_put_pixel(col, y, get_tpx(cub, dist, wall_height, y), cub);
		y++;
	}
}
