/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate_map_closed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:39:35 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 15:39:19 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_push(t_cub3d *cub, t_xy **stack, int x, int y)
{
	t_xy	*new;

	if (!stack)
		error_exit(cub, "Unexpected empty ptr (push).");
	new = malloc(sizeof(t_xy));
	if (!new)
		error_exit(cub, "Malloc failed (ft_push).");
	new->x = x;
	new->y = y;
	new->next = *stack;
	*stack = new;
}

static void	ft_pop(t_xy **stack)
{
	t_xy	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

static void	init_dxdy(int (*dx)[4], int (*dy)[4])
{
	(*dx)[0] = 0;
	(*dx)[1] = 0;
	(*dx)[2] = -1;
	(*dx)[3] = 1;
	(*dy)[0] = -1;
	(*dy)[1] = 1;
	(*dy)[2] = 0;
	(*dy)[3] = 0;
}

static int	update_stack(t_cub3d *cub, int x, int y)
{
	int	i;
	int	nx;
	int	ny;
	int	dx[4];
	int	dy[4];

	init_dxdy(&dx, &dy);
	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (out_of_map(cub, nx, ny))
			return (set_error(cub, "Map not closed."));
		if (cub->raw_map[ny][nx] == '0' || cub->raw_map[ny][nx] == ' ')
			ft_push(cub, &cub->stack, nx, ny);
		i++;
	}
	return (1);
}

int	map_closed(t_cub3d *cub, char **map)
{
	int	x;
	int	y;

	x = cub->px;
	y = cub->py;
	cub->player.x = (float)cub->px;
	cub->player.y = (float)cub->py;
	map[y][x] = '0';
	ft_push(cub, &cub->stack, x, y);
	while (cub->stack)
	{
		x = cub->stack->x;
		y = cub->stack->y;
		ft_pop(&cub->stack);
		if (out_of_map(cub, x, y))
			return (set_error(cub, "Tile out of map (map_closed)."));
		if (map[y][x] == '1' || map[y][x] == '8')
			continue ;
		map[y][x] = '8';
		if (!update_stack(cub, x, y))
			return (set_error(cub,
					"Tile out of map (update_stack-> map_close)."));
	}
	return (1);
}
