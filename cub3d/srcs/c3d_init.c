/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:31:22 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/23 09:34:48 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	init_ptrs(t_cub3d *cub)
{
	cub->line = NULL;
	cub->east = NULL;
	cub->south = NULL;
	cub->west = NULL;
	cub->north = NULL;
	cub->raw_args = NULL;
	cub->raw_map = NULL;
	cub->map = NULL;
	cub->err_msg = NULL;
	cub->read = ft_calloc(1, sizeof(char *));
	cub->raw_args = ft_calloc(1, sizeof(char *));
	cub->raw_map = ft_calloc(1, sizeof(char *));
	cub->map = NULL;
	cub->err_msg = ft_calloc(1, sizeof(char *));
	if (!cub->read || !cub->raw_args || !cub->raw_map || !cub->err_msg)
		return (set_error(cub, "Malloc failed (init_ptrs)."));
	cub->tex_e.img_ptr = NULL;
	cub->tex_w.img_ptr = NULL;
	cub->tex_s.img_ptr = NULL;
	cub->tex_n.img_ptr = NULL;
	return (1);
}

static void	init_ints(t_cub3d *cub)
{
	int	i;

	i = -1;
	while (xy_iterator(NULL, 0, &i, 3))
		cub->floor[i] = -1;
	i = -1;
	while (xy_iterator(NULL, 0, &i, 3))
		cub->ceiling[i] = -1;
	cub->fd = -1;
	cub->mw = 0;
	cub->mh = 0;
	cub->px = -1;
	cub->py = -1;
	cub->po = -1;
	cub->east_i = 0;
	cub->south_i = 0;
	cub->west_i = 0;
	cub->north_i = 0;
	cub->ceiling_i = 0;
	cub->floor_i = 0;
}

static void	init_stack(t_cub3d *cub)
{
	cub->stack = NULL;
}

int	init(t_cub3d *cub)
{
	init_ints(cub);
	if (!init_ptrs(cub))
		return (set_error(cub, "Init stoped (ptrs)."));
	init_stack(cub);
	return (1);
}
