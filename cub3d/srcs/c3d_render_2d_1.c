/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_2d_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:24:46 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/25 19:26:11 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_map_2d(t_cub3d *cub)
{
	t_point	xy;
	t_point	xy_aux;

	xy.y = -1;
	xy_aux.x = 0;
	xy_aux.y = 0;
	while (cub->map[(int)(++xy.y)])
	{
		xy.x = -1;
		while (cub->map[(int)xy.y][(int)++xy.x])
		{
			if (cub->map[(int)xy.y][(int)xy.x] == '1')
			{
				xy_aux.x = xy.x * BLOCK;
				xy_aux.y = xy.y * BLOCK;
				if (cub->player.t_c < 0)
					ft_draw_square_2d(xy_aux, BLOCK, RED_PIXEL, cub);
				else
					ft_draw_texture_block_2d(xy_aux, cub);
			}
		}
	}
	ft_draw_rays_2d(cub);
}

void	ft_draw_texture_block_2d(t_point xy, t_cub3d *c)
{
	t_img		*ptr;
	t_int_point	tex;
	t_int_point	block;
	int			color;
	char		*texture_data;

	ptr = &c->tex_n;
	texture_data = mlx_get_data_addr(ptr->img_ptr, &ptr->bpp, &ptr->size_line,
			&ptr->endian);
	block.x = -1;
	block.y = 0;
	while (xy_iterator(&block.y, BLOCK, &block.x, BLOCK))
	{
		tex.x = (block.x * c->i_w) / BLOCK;
		tex.y = (block.y * c->i_h) / BLOCK;
		tex.x %= c->i_w;
		tex.y %= c->i_h;
		color = *(int *)(texture_data + (tex.y * ptr->size_line + tex.x
					* (ptr->bpp / 8)));
		ft_put_pixel(xy.x + block.x, xy.y + block.y, color, c);
	}
}

static void	ft_draw_square_solid_2d(t_point xy, int size, int color,
		t_cub3d *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel(xy.x + i, xy.y + j, color, ptr);
			j++;
		}
		i++;
	}
}

void	ft_draw_square_2d(t_point xy, int size, int color, t_cub3d *ptr)
{
	int	i;

	i = 0;
	while (i < size)
		ft_put_pixel(xy.x + i++, xy.y, color, ptr);
	i = 0;
	while (i < size)
		ft_put_pixel(xy.x, xy.y + i++, color, ptr);
	i = 0;
	while (i < size)
		ft_put_pixel(xy.x + size, xy.y + i++, color, ptr);
	i = 0;
	while (i < size)
		ft_put_pixel(xy.x + i++, xy.y + size, color, ptr);
}

void	ft_draw_minimap_2d(t_cub3d *cub)
{
	t_int_point	xy;
	t_int_point	pl;
	t_int_point	o_set;
	int			size;

	size = BLOCK * MINIMAP_SCALE;
	xy.x = -1;
	xy.y = 0;
	while (xy_iterator(&xy.y, cub->mh, &xy.x, cub->mw))
	{
		o_set.x = MINIMAP_OFFSET_X + xy.x * size;
		o_set.y = MINIMAP_OFFSET_Y + xy.y * size;
		if (cub->map[xy.y][xy.x] == '1')
			ft_draw_square_solid_2d((t_point){o_set.x, o_set.y}, size, 0x000000,
				cub);
		else
			ft_draw_square_solid_2d((t_point){o_set.x, o_set.y}, size,
				WHITE_PIXEL, cub);
	}
	pl.x = MINIMAP_OFFSET_X + (int)(cub->player.x / BLOCK) * size;
	pl.y = MINIMAP_OFFSET_Y + (int)(cub->player.y / BLOCK) * size;
	ft_draw_square_solid_2d((t_point){pl.x, pl.y}, size / 2, GREEN_PIXEL, cub);
}
