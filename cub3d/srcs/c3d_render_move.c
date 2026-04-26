/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:00:33 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 18:10:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ft_orientation(char c)
{
	if (c == 'W')
		return (PI);
	if (c == 'S')
		return (PI / 2);
	if (c == 'E')
		return (0);
	else
		return (3 * PI / 2);
}

void	ft_norm_angle(t_cub3d *cub, float angle)
{
	(void)cub;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
}

static void	ft_make_move(t_cub3d *cub, float *move_x, float *move_y)
{
	if (cub->player.key_up)
	{
		*move_x += cos(cub->player.angle) * SPEED;
		*move_y += sin(cub->player.angle) * SPEED;
	}
	if (cub->player.key_down)
	{
		*move_x -= cos(cub->player.angle) * SPEED;
		*move_y -= sin(cub->player.angle) * SPEED;
	}
	if (cub->player.key_rigth)
	{
		*move_x -= sin(cub->player.angle) * SPEED / 2;
		*move_y += cos(cub->player.angle) * SPEED / 2;
	}
	if (cub->player.key_left)
	{
		*move_x += sin(cub->player.angle) * SPEED / 2;
		*move_y -= cos(cub->player.angle) * SPEED / 2;
	}
}

void	ft_move_player(t_cub3d *cub)
{
	t_player	*pl;
	float		m_x;
	float		m_y;

	pl = &cub->player;
	m_x = 0;
	m_y = 0;
	if (pl->left_rot || pl->right_rot)
	{
		pl->angle += -INC_ANGL * pl->left_rot + INC_ANGL * pl->right_rot;
		ft_norm_angle(cub, pl->angle);
	}
	ft_make_move(cub, &m_x, &m_y);
	if (ft_in_limit(pl->x + m_x, pl->y, cub))
		pl->x += m_x;
	if (ft_in_limit(pl->x, pl->y + m_y, cub))
		pl->y += m_y;
}
