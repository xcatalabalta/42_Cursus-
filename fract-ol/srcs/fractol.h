/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:40:45 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/23 16:42:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "mac_key.h"

# define WIDTH 1600 
# define HEIGHT 1200
# define IT_MIN 50
# define IT_MAX 500
# define SC_MIN 0.05
# define SC_INI 0.75
# define MV_HOR 10
# define MV_VER 20
# define INC_IT 0.10
# define NAME_1 "Mandelbrot"
# define NAME_2 "Julia"

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*ptr;
	char	*buf_pix;
	int		bits_pix;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_data
{
	int		type;
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	scale;
	int		iter;	
	double	shift_h;
	double	shift_v;
	double	c_real;
	double	c_imag;
}				t_data;

int		mouse_c(int input, int x, int y, t_data *pr);
int		key_c(int input, t_data *pr);
void	pixel_imag(t_img *img, int x, int y, int color);
void	draw_fractol(t_data *pr);
void	draw_manda(t_data *pr);
void	draw_julia(t_data *pr);
int		check_set(t_complex ab, t_complex c, int iter);
void	init_show(t_data *pr);
void	free_char(char **str);
char	*ft_strlow(char *str);
double	ft_atod(const char *str);
#endif
