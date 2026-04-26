/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:13:34 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 15:57:54 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	ft_getrgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	get_col(t_cub3d *cub, t_img *texture)
{
	if (texture == &cub->tex_e)
		return (AQUA_PIXEL);
	else if (texture == &cub->tex_s)
		return (YELL_PIXEL);
	else if (texture == &cub->tex_w)
		return (RED_PIXEL);
	else if (texture == &cub->tex_n)
		return (GREEN_PIXEL);
	return (MAGEN_PIXEL);
}

//t_point		d_h[2]; 0 para raydir, 1 para hit
static void	ft_get_tpx_x(t_cub3d *cub, float dist, t_img *tex, t_int_point *t_p)
{
	t_point		d_h[2];

	d_h[0].x = cosf(cub->player.ray_angle);
	d_h[0].y = sinf(cub->player.ray_angle);
	d_h[1].x = cub->player.x + d_h[0].x * dist;
	d_h[1].y = cub->player.y + d_h[0].y * dist;
	if (cub->side == 0)
	{
		if (d_h[0].x > 0)
			t_p->x = tex->width - 1
				- (int)((fmodf(d_h[1].y, BLOCK) / BLOCK) * tex->width);
		else
			t_p->x = (int)((fmodf(d_h[1].y, BLOCK) / BLOCK) * tex->width);
	}
	else
	{
		if (d_h[0].y > 0)
			t_p->x = tex->width - 1 - (int)((fmodf(d_h[1].x, BLOCK) / BLOCK)
					* tex->width);
		else
			t_p->x = (int)((fmodf(d_h[1].x, BLOCK) / BLOCK) * tex->width);
	}
}

static void	ft_get_tpx_y(t_img *tex, t_int_point *t_p)
{
	if (t_p->x < 0)
		t_p->x = 0;
	if (t_p->x >= tex->width)
		t_p->x = tex->width - 1;
	if (t_p->y < 0)
		t_p->y = 0;
	if (t_p->y >= tex->height)
		t_p->y = tex->height - 1;
}

int	get_tpx(t_cub3d *cub, float dist, int wall_height, int y)
{
	int			offset;
	t_img		*tex;
	t_int_point	t_p;
	float		line_start;

	tex = cub->t_put;
	if (cub->player.t_c == 1)
	{
		ft_get_tpx_x(cub, dist, tex, &t_p);
		line_start = (HEIGHT / 2.0f) - (wall_height / 2.0f);
		t_p.y = (int)(((y - line_start) * tex->height) / wall_height);
		ft_get_tpx_y(tex, &t_p);
		offset = (t_p.y * tex->size_line) + (t_p.x * (tex->bpp / 8));
		if (!tex->data)
		{
			error_exit(cub, "Texture data is NULL");
		}
		return (*(int *)(tex->data + offset));
	}
	else
	{
		return (get_col(cub, cub->t_put));
	}
}
