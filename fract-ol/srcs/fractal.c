/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:21 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/23 15:56:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_imag(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_pix / 8));
	if (offset >= 0 && offset < img->line_len * HEIGHT)
		*((unsigned int *)(offset + img->buf_pix)) = color;
}

int	check_set(t_complex ab, t_complex c, int iter)
{
	int		i;
	double	t;

	i = 0;
	while (++i <= iter)
	{
		t = c.real;
		c.real = (c.real * c.real) - (c.imag * c.imag) + ab.real;
		c.imag = 2 * t * c.imag + ab.imag;
		if ((c.real * c.real) + (c.imag * c.imag) > 4)
			break ;
	}
	return (i);
}

void	draw_julia(t_data *pr)
{
	t_point		xy;
	t_complex	ab;
	t_complex	comp;
	int			color;
	int			ctr;

	xy.y = -1;
	while (++xy.y <= HEIGHT)
	{
		comp.imag = 2 - ((xy.y + pr->shift_v) / pr->scale);
		xy.x = -1;
		while (++xy.x <= WIDTH)
		{
			comp.real = -2 + ((xy.x + pr->shift_h) / pr->scale);
			ab.real = pr->c_real;
			ab.imag = pr->c_imag;
			ctr = check_set(ab, comp, pr->iter);
			color = (0xFEDCBA - 0xABCDEF) * (ctr - 1) / pr->iter + 0xABCDEF;
			pixel_imag(&pr->img, xy.x, xy.y, color);
		}
	}
	mlx_put_image_to_window(pr->mlx, pr->win, pr->img.ptr, 0, 0);
}

void	draw_manda(t_data *pr)
{
	t_point		xy;
	t_complex	ab;
	t_complex	comp;
	int			color;
	int			ctr;

	xy.y = -1;
	while (++xy.y <= HEIGHT)
	{
		ab.imag = 2 - ((xy.y + pr->shift_v) / pr->scale);
		xy.x = -1;
		while (++xy.x <= WIDTH)
		{
			ab.real = -2 + ((xy.x + pr->shift_h) / pr->scale);
			comp.real = 0;
			comp.imag = 0;
			ctr = check_set(ab, comp, pr->iter);
			color = (0xFEDCBA - 0xABCDEF) * (ctr - 1) / pr->iter + 0xABCDEF;
			pixel_imag(&pr->img, xy.x, xy.y, color);
		}
	}
	mlx_put_image_to_window(pr->mlx, pr->win, pr->img.ptr, 0, 0);
}

void	draw_fractol(t_data *pr)
{
	if (pr->type == 1)
		draw_manda(pr);
	else if (pr->type == 2)
		draw_julia(pr);
}
