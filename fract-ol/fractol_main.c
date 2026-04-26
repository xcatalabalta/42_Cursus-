/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:13:32 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/23 16:16:34 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/fractol.h"

void	menu(void)
{
	ft_printf("Valid set of options:\n");
	ft_printf("1.- Fractal types:\n\tMandelbrot\n\tJulia\n");
	ft_printf("2.- Iterations from 5 to 100\n");
	ft_printf("3.- Initial parameters (for Julia only)\n");
	ft_printf("\tReal component [-3;3]\n");
	ft_printf("\tImaginary component [-1;1]\n");
	ft_printf("\n\nControl options:\n");
	ft_printf("\tMove image with arrow keys\n");
	ft_printf("\tZoom in/out with mouse wheel or +/- keys\n");
	ft_printf("\tMove point to center with mous clic\n");
}

void	parsing(char **str, int ctr, t_data *pr)
{
	pr->type = 0;
	if (!ft_strncmp(ft_strlow(str[ctr + 1]), "mandelbrot", 10))
		pr->type = 1;
	else if (!ft_strncmp(ft_strlow(str[ctr + 1]), "julia", 5))
		pr->type = 2;
	if (pr->type && (ft_atoi(str[ctr + 2]) > 4 && ft_atoi(str[ctr + 2]) < 101))
		pr->iter = ft_atoi(str[ctr + 2]);
	else
		pr->type = 0;
	if (pr->type == 2)
	{
		if ((ft_atod(str[ctr + 3]) >= -3 && ft_atod(str[ctr + 3]) <= 3)
			&& (ft_atod(str[ctr + 4]) >= -1 && ft_atod(str[ctr + 4]) <= 1))
		{
			pr->c_real = ft_atod(str[ctr + 3]);
			pr->c_imag = ft_atod(str[ctr + 4]);
		}
		else
			pr->type = 0;
	}
	if (pr->type == 0)
	{
		menu();
		exit(EXIT_FAILURE);
	}
}

void	init_mlx(t_data *pr)
{
	pr->mlx = mlx_init();
	if (!pr->mlx)
		exit(EXIT_FAILURE);
	if (pr->type == 1)
		pr->name = (char *)(NAME_1);
	else if (pr->type == 2)
		pr->name = (char *)(NAME_2);
	pr->win = mlx_new_window(pr->mlx, WIDTH, HEIGHT, pr->name);
	if (!pr->win)
	{
		free(pr->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_show(t_data *pr)
{
	pr->img.ptr = mlx_new_image(pr->mlx, WIDTH, HEIGHT);
	pr->img.buf_pix = mlx_get_data_addr(pr->img.ptr, &pr->img.bits_pix,
			&pr->img.line_len, &pr->img.endian);
	pr->scale = SC_INI * (HEIGHT / 4);
	pr->shift_h = -(WIDTH - SC_INI * HEIGHT) / 2;
	pr->shift_v = -(1 - SC_INI) * HEIGHT / 2;
}

int	main(int argc, char **argv)
{
	t_data	pr;
	char	**values;

	if (argc >= 2)
	{
		if (argc == 2)
		{
			values = ft_split(argv[1], 32);
			parsing(values, -1, &pr);
			free_char(values);
		}
		else
			parsing(argv, 0, &pr);
		init_mlx(&pr);
		init_show(&pr);
		draw_fractol(&pr);
		mlx_key_hook(pr.win, key_c, &pr);
		mlx_mouse_hook(pr.win, mouse_c, &pr);
		mlx_loop(pr.mlx);
		free(pr.mlx);
	}
	else
		menu();
	return (0);
}
