/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:36:08 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/27 19:52:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_click_cross(t_cub3d *cub)
{
	if (cub)
	{
		if (cub->mlx)
		{
			if (cub->win)
				mlx_destroy_window(cub->mlx, cub->win);
			if (cub->img)
				mlx_destroy_image(cub->mlx, cub->img);
			if (cub->tex_s.img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_s.img_ptr);
			if (cub->tex_e.img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_e.img_ptr);
			if (cub->tex_w.img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_w.img_ptr);
			if (cub->tex_n.img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_n.img_ptr);
			mlx_destroy_display(cub->mlx);
			free(cub->mlx);
		}
		free_ptrs(cub);
		free_double_ptrs(cub);
		free_stack(cub);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_rot_mouse(int x, int y, t_cub3d *cub)
{
	if (cub->player.view == -1)
	{
		if (y != -1)
			cub->player.angle += (x - cub->mouse_x) * INC_ANGL / 24;
	}
	else
	{
		if (y != -1 && y > cub->player.y)
			cub->player.angle += (x - cub->mouse_x) * INC_ANGL
				/ 2 * (-1 + 2 * (sinf(cub->player.angle < 0)));
		else if (y != -1 && y < cub->player.y)
			cub->player.angle -= (x - cub->mouse_x) * INC_ANGL
				/ 2 * (-1 + 2 * (sinf(cub->player.angle < 0)));
	}
	cub->mouse_x = x;
	return (0);
}

//cub->player.view *= -1; //switch (1) 2d (-1) 3d 
//cub->player.t_c *= -1; //switch (1 texture -1 color)
int	ft_key_press(int keycode, t_cub3d *cub)
{
	if (keycode == ESC_KEY)
	{
		ft_click_cross(cub);
		cub->win = NULL;
	}
	if (keycode == W_KEY || keycode == UP_KEY)
		cub->player.key_up = true;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		cub->player.key_down = true;
	if (keycode == A_KEY)
		cub->player.key_left = true;
	if (keycode == D_KEY)
		cub->player.key_rigth = true;
	if (keycode == LEFT_KEY)
		cub->player.left_rot = true;
	if (keycode == RIGHT_KEY)
		cub->player.right_rot = true;
	if (keycode == V_KEY)
		cub->player.view *= -1;
	if (keycode == T_KEY)
		cub->player.t_c *= -1;
	return (0);
}

int	ft_key_release(int keycode, t_cub3d *cub)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		cub->player.key_up = false;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		cub->player.key_down = false;
	if (keycode == A_KEY)
		cub->player.key_left = false;
	if (keycode == D_KEY)
		cub->player.key_rigth = false;
	if (keycode == LEFT_KEY)
		cub->player.left_rot = false;
	if (keycode == RIGHT_KEY)
		cub->player.right_rot = false;
	return (0);
}
