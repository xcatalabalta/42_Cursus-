/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:51:36 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/23 16:04:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	finish(t_data *pr)
{
	mlx_destroy_image(pr->mlx, pr->img.ptr);
	mlx_destroy_window(pr->mlx, pr->win);
	free(pr->mlx);
	exit (0);
}

static void zoom(t_data *pr, int input)
{
	double	ini;

	ini = pr->scale;
	if (input == 1)
	{
		pr->scale *= (1 + INC_IT);
		if (pr->iter <= IT_MAX - 5)
			pr->iter += 5;
	}
	else if (input == 2)
	{
		if (pr->scale >= SC_MIN * (HEIGHT / 4))
			pr->scale *= (1 - INC_IT);
		if (pr->iter >= IT_MIN + 5)
			pr->iter -= 5;
		}
}

int	key_c(int input, t_data *pr)
{
	if (input == ESC)
		finish(pr);
	else if (input == UP_ARROW || input == W_KEY)
		pr->shift_v += MV_VER;
	else if (input == DOWN_ARROW || input == S_KEY)
		pr->shift_v -= MV_VER;
	else if (input == LEFT_ARROW || input == D_KEY)
		pr->shift_h += MV_HOR;
	else if (input == RIGHT_ARROW || input == A_KEY)
		pr->shift_h -= MV_HOR;
	else if (input == PLUS_KEY)
		zoom(pr, 1);
	else if (input == MINUS_KEY)
		zoom(pr, 2);
	draw_fractol(pr);
	return (0);
}

int	mouse_c(int input, int x, int y, t_data *pr)
{
	if (x > 0 && y > 0)
	{
		if (input == DOWN_SCROLL)
			zoom(pr, 1);
		else if (input == UP_SCROLL)
			zoom(pr, 2);
		else if (input == 1)
		{
			pr->shift_v += y - HEIGHT / 2;
			pr->shift_h += x - WIDTH / 2;
		}
	}
	draw_fractol(pr);
	return (0);
}
