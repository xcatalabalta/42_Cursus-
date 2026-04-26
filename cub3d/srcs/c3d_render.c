/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:49:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/26 15:42:26 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	render_background(t_cub3d *cub)
{
	int				x;
	int				y;
	unsigned long	c;
	unsigned long	f;

	c = ft_getrgb(cub->ceiling[0], cub->ceiling[1], cub->ceiling[2]);
	f = ft_getrgb(cub->floor[0], cub->floor[1], cub->floor[2]);
	x = -1;
	y = 0;
	while (xy_iterator(&y, HEIGHT, &x, WIDTH))
	{
		if (y < HEIGHT / 2 && (cub->player.view == -1))
			ft_put_pixel(x, y, c, cub);
		else
			ft_put_pixel(x, y, f, cub);
	}
}

static void	ft_view_2d(t_cub3d *cub)
{
	t_point	pl;

	ft_draw_map_2d(cub);
	pl.x = cub->player.x - MINI / 2;
	pl.y = cub->player.y - MINI / 2;
	ft_draw_square_2d(pl, MINI, GREEN_PIXEL, cub);
}

static int	render(t_cub3d *cub)
{
	float	initial_angle;

	if (cub->win == NULL)
		ft_click_cross(cub);
	ft_move_player(cub);
	render_background(cub);
	if (cub->player.view == 1)
	{
		ft_view_2d(cub);
	}
	else
	{
		initial_angle = cub->player.angle - (FOV / 2);
		cub->i = -1;
		while (++cub->i < WIDTH)
		{
			ft_draw_line_3d(&cub->player, cub, initial_angle, cub->i);
			initial_angle += FOV / WIDTH;
		}
	}
	ft_draw_minimap_2d(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

int	cub_run(t_cub3d *cub)
{
	ft_init_player(cub);
	ft_init_game(cub);
	mlx_loop_hook(cub->mlx, &render, cub);
	mlx_hook(cub->win, 2, 1L << 0, &ft_key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, &ft_key_release, cub);
	mlx_hook(cub->win, 17, 1L << 17, &ft_click_cross, cub);
	mlx_hook(cub->win, 6, 1L << 6, &ft_rot_mouse, cub);
	mlx_loop(cub->mlx);
	return (0);
}
