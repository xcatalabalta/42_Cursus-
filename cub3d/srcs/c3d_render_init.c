/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:51:13 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/19 00:09:36 by mvisca           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//cub->coloret = WHITE_PIXEL; // Color por defecto
static void	ft_init_aux(t_cub3d *cub)
{
	cub->i_h = BLOCK;
	cub->i_w = BLOCK;
	cub->coloret = WHITE_PIXEL;
	cub->sx = 0;
	cub->sy = 0;
	cub->cx = 0;
	cub->cy = 0;
	cub->mlx = NULL;
	cub->win = NULL;
	cub->img = NULL;
	cub->data = NULL;
	cub->mouse_x = 0;
}

//player->t_c = 1; //alterna visualizacion (1 textura -1 color)
void	ft_init_player(t_cub3d *cub)
{
	t_player	*player;

	player = &cub->player;
	player->x = cub->px * BLOCK + BLOCK / 2;
	player->y = cub->py * BLOCK + BLOCK / 2;
	player->angle = ft_orientation(cub->po);
	player->key_up = false;
	player->key_down = false;
	player->key_rigth = false;
	player->key_left = false;
	player->left_rot = false;
	player->right_rot = false;
	player->view = -1;
	player->t_c = 1;
}

// Función auxiliar para cargar una textura y manejar errores
void	load_texture(t_cub3d *cub, char *path, t_img *tex)
{
	tex->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img_ptr)
		error_exit(cub, "Cannot load texture.");
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line,
			&tex->endian);
	if (!tex->data)
		error_exit(cub, "Cannot get texture data.");
}

void	ft_load_textures(t_cub3d *cub)
{
	load_texture(cub, cub->east, &cub->tex_e);
	load_texture(cub, cub->south, &cub->tex_s);
	load_texture(cub, cub->west, &cub->tex_w);
	load_texture(cub, cub->north, &cub->tex_n);
}

void	ft_init_game(t_cub3d *cub)
{
	ft_init_aux(cub);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_exit(cub, "Faile to initialize MLX Display.");
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub");
	if (!cub->win)
	{
		mlx_destroy_display(cub->mlx);
		error_exit(cub, "Faile to initialize MLX Window.");
	}
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		error_exit(cub, "Faile to initialize MLX Image.");
	}
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line,
			&cub->endian);
	ft_load_textures(cub);
}
