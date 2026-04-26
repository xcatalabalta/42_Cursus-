/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:55:18 by mvisca-g          #+#    #+#             */
/*   Updated: 2025/02/27 19:37:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// System libraries
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdbool.h>

// Custom libraries
# include "../libs/libft/include/libft.h"
# include "../libs/gnl/include/get_next_line.h"

// Minilibx
# include "../libs/minilibx-linux/mlx.h"

// Structures
# include "structs.h"

// Font colors
# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define NC      "\033[0m"

// Pixel colors
# define RED_PIXEL   0xFF0000
# define GREEN_PIXEL 0xFF00
# define MAGEN_PIXEL 0xFF00FF
# define WHITE_PIXEL 0xFFFFFF
# define AQUA_PIXEL  0x00FFFF
# define YELL_PIXEL  0xFFFF00

// Screen dimensions
//in 42 W 3840  H 2048 //at home W 1080 H 720
# define WIDTH      2000
# define HEIGHT     1000

// 2d Dimensions
# define BLOCK      64
# define MINI       16

// Minimap dimensions
# define MINIMAP_SCALE 0.2
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10

// Movement
# define PI         3.14159265359
# define FOV        1.047197551
# define SPEED      25
# define INC_ANGL   0.1

// Keys
# define W_KEY      119
# define A_KEY      97
# define S_KEY      115
# define D_KEY      100
# define V_KEY      118
# define T_KEY      116
# define ESC_KEY    65307
# define UP_KEY     65362
# define DOWN_KEY   65364
# define LEFT_KEY   65361
# define RIGHT_KEY	65363

//---------------------------------------------------

// Prototypes and files

// c3d.c (main)
void			show_map(char **map);

// c3d_errors.c
void			error_exit(t_cub3d *cub, char *msg);
int				set_error(t_cub3d *cub, char *msg);

// c3d_free1.c
void			free_tab(char ***tab);
void			free_line(char **line);
void			free_all(t_cub3d *cub);

// c3d_free1.c
void			free_double_ptrs(t_cub3d *cub);
void			free_stack(t_cub3d *cub);
void			free_ptrs(t_cub3d *cub);

// c3d_logic_utils.c 
int				xy_iterator(int *y_s, int y_e, int *x_s, int x_e);
int				all_config_assigned(t_cub3d *cub, int in_map);
int				valid_chars(t_cub3d *cub, char *line, char *allowed_chars);
float			ft_tern(float base, float compare, float if_t, float if_f);

// c3d_utils.c
int				check_pathname(t_cub3d *cub, char *pname, char *ext);
int				replace_chars(char **line, char ori, char rep);
int				clean_redundant_spaces(char **line);
int				push_line_to(t_cub3d *cub, char *line, char ***dest);
void			replace_tabs(t_cub3d *cub, char **line);

// c3d_init.c + 3 static
int				init(t_cub3d *cub);

// c3d_parse.c + 2 static
int				parse(t_cub3d *cub, char *pathname);

// c3d_parse_process.c + 3 static
int				map_process(t_cub3d *cub, int i);
int				read_process(t_cub3d *cub);

// c3d_validate.c
int				validate(t_cub3d *cub);

// c3d_validate_arg.c
int				validate_args(t_cub3d *cub);

// c3d_validate_texture.c
int				texture_process(t_cub3d *cub, char *line);
int				validate_map(t_cub3d *cub);

// c3d_validate_rgb.c + 2 static
int				rgb_process(t_cub3d *cub, char *line);

// c3d_validate_map_closed.c + 4 static
int				map_closed(t_cub3d *cub, char **map);

// c3d_validate_map.c + 3 static
int				out_of_map(t_cub3d *cub, int x, int y);
void			normalize_map_width(t_cub3d *cub);

// srcs/c3d_render.c + 3 static
int				cub_run(t_cub3d *cub);

// srcs/c3d_render_init.c
void			load_texture(t_cub3d *cub, char *path, t_img *tex);
void			ft_load_textures(t_cub3d *cub);
void			ft_init_player(t_cub3d *cub);
void			ft_init_game(t_cub3d *cub);

// srcs/c3d_render_get.c + 2 static
unsigned long	ft_getrgb(int r, int g, int b);
int				get_tpx(t_cub3d *c, float dist, int wall_height, int y);
int				get_col(t_cub3d *cub, t_img *texture);

//srcs/c3d_render_3d_2.c + 2 static
float			ft_pdst(int side, t_point sdp[3], float ang, t_int_point ms[2]);
float			ft_cast_ray_3d(float p_x, float p_y, float a, t_cub3d *c);

//srcs/c3d_render_3d_1.c + 1 static
void			ft_draw_line_3d(t_player *p, t_cub3d *c, float s_x, int i);

// srcs/c3d_render_2d_2.c
void			ft_init_bresenham(t_bresenham *b, t_point start, t_point end);
void			ft_draw_line_2d(t_cub3d *cub, t_point s, t_point e, int c);
void			ft_draw_rays_2d(t_cub3d *cub);

// srcs/c3d_render_2d_1.c + 1 static
void			ft_draw_map_2d(t_cub3d *cub);
void			ft_draw_texture_block_2d(t_point xy, t_cub3d *cub);
void			ft_draw_square_2d(t_point xy, int s, int c, t_cub3d *cub);
void			ft_draw_minimap_2d(t_cub3d *cub);

// srcs/c3d_render_utils.c
bool			ft_in_limit(float x, float y, t_cub3d *cub);
bool			ft_touch(float px, float py, t_cub3d *cub);
float			ft_distance(float x, float y);
void			ft_put_pixel(int x, int y, int color, t_cub3d *cub);

// srcs/c3d_render_hooks.c
int				ft_click_cross(t_cub3d *cub);
int				ft_rot_mouse(int x, int y, t_cub3d *cub);
int				ft_key_press(int keycode, t_cub3d *cub);
int				ft_key_release(int keycode, t_cub3d *cub);

// srcs/c3d_render_move.c + 1 static
void			ft_move_player(t_cub3d *cub);
float			ft_orientation(char c);
void			ft_norm_angle(t_cub3d *cub, float angle);

#endif
