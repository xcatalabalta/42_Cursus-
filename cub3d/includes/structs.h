/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:36:00 by mvisca-g          #+#    #+#             */
/*   Updated: 2025/02/26 12:39:23 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_bresenham
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}	t_bresenham;

// Casillas que se visitan en el flood fill
typedef struct s_xy
{
	int			x;
	int			y;
	struct s_xy	*next;
}	t_xy;

typedef struct s_point
{
	float		x;
	float		y;
}	t_point;

typedef struct int_point
{
	int			x;
	int			y;
}	t_int_point;

typedef struct s_hit
{
	t_point		hit_xy;
	float		dist;
}	t_hit;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

// Jugador
typedef struct player
{
	float		x;
	float		y;
	float		angle;
	float		ray_angle;
	bool		key_up;
	bool		key_down;
	bool		key_rigth;
	bool		key_left;	
	bool		left_rot;
	bool		right_rot;
	int			view;
	char		look_to;
	int			t_c;
}	t_player;

typedef struct s_cub3d
{
	char			*east;
	char			*south;
	char			*north;
	char			*west;
	int				east_i;
	int				south_i;
	int				west_i;
	int				north_i;
	int				floor[3];
	int				ceiling[3];
	int				floor_i;
	int				ceiling_i;
	char			**map;
	int				mw;
	int				mh;
	int				sx;
	int				sy;
	int				cx;
	int				cy;
	int				px;
	int				py;
	char			po;
	int				i;
	int				fd;
	char			*line;
	char			**read;
	char			**raw_args;
	char			**raw_map;
	char			**err_msg;
	int				side;
	void			*win;
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				tx_bpp;
	int				tx_size_l;
	int				tx_endian;
	t_img			tex_n;
	t_img			tex_s;
	t_img			tex_e;
	t_img			tex_w;
	int				i_h;
	int				i_w;
	int				coloret;
	void			*t_put;
	t_player		player;
	int				mouse_x;
	t_xy			*stack;
}	t_cub3d;

#endif
