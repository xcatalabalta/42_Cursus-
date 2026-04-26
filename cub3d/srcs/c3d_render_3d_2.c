/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_3d_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:24 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/01 08:50:31 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ft_pdst(int side, t_point sdp[3], float ang, t_int_point ms[2])
{
	float	pdst;

	if (side == 0)
		pdst = (ms[0].x - sdp[2].x / BLOCK + (1 - ms[1].x) / 2.0f) / cosf(ang);
	else
		pdst = (ms[0].y - sdp[2].y / BLOCK + (1 - ms[1].y) / 2.0f) / sinf(ang);
	return (pdst);
}

static float	ft_get_perp_dist(t_cub3d *cub, t_point sdp[3], float ang,
		t_int_point ms[2])
{
	int		hit_side[2];
	float	pdst;

	hit_side[0] = 0;
	hit_side[1] = 0;
	while (!hit_side[0])
	{
		if (sdp[0].x < sdp[0].y)
		{
			sdp[0].x += sdp[1].x;
			ms[0].x += ms[1].x;
			hit_side[1] = 0;
		}
		else
		{
			sdp[0].y += sdp[1].y;
			ms[0].y += ms[1].y;
			hit_side[1] = 1;
		}
		if (cub->map[ms[0].y][ms[0].x] == '1')
			hit_side[0] = 1;
	}
	pdst = ft_pdst(hit_side[1], sdp, ang, ms);
	cub->side = hit_side[1];
	return (pdst);
}

static void	ft_set_cast_r3d(t_int_point **mp_stp, t_point **sdp, float angle)
{
	if (cosf(angle) < 0)
	{
		mp_stp[1]->x = -1;
		sdp[0]->x = ((sdp[2]->x / BLOCK) - mp_stp[0]->x) * sdp[1]->x;
	}
	else
	{
		mp_stp[1]->x = 1;
		sdp[0]->x = ((mp_stp[0]->x + 1) - (sdp[2]->x / BLOCK)) * sdp[1]->x;
	}
	if (sinf(angle) < 0)
	{
		mp_stp[1]->y = -1;
		sdp[0]->y = ((sdp[2]->y / BLOCK) - mp_stp[0]->y) * sdp[1]->y;
	}
	else
	{
		mp_stp[1]->y = 1;
		sdp[0]->y = ((mp_stp[0]->y + 1) - (sdp[2]->y / BLOCK)) * sdp[1]->y;
	}
}

//s_d_p [0]side_xy; [1]delta_xy; [2]player_xy
//mp_stp [0]map_xy; [1]step_xy
float	ft_cast_ray_3d(float player_x, float player_y, float angle,
		t_cub3d *cub)
{
	t_int_point	mp_stp[2];
	t_point		s_d_p[3];
	float		perdst;

	s_d_p[2].x = player_x;
	s_d_p[2].y = player_y;
	mp_stp[0].x = (int)(s_d_p[2].x / BLOCK);
	mp_stp[0].y = (int)(s_d_p[2].y / BLOCK);
	s_d_p[1].x = ft_tern(cosf(angle), 0, 1e30, fabsf(1.0f / cosf(angle)));
	s_d_p[1].y = ft_tern(sinf(angle), 0, 1e30, fabsf(1.0f / sinf(angle)));
	ft_set_cast_r3d((t_int_point *[]){&mp_stp[0], &mp_stp[1]},
		(t_point *[]){&s_d_p[0], &s_d_p[1], &s_d_p[2]}, angle);
	perdst = ft_get_perp_dist(cub, s_d_p, angle, mp_stp);
	return (perdst * BLOCK);
}
