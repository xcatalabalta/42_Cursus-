/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_free2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:48:16 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 08:39:08 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_ptrs(t_cub3d *cub)
{
	if (cub->east)
		free_line(&cub->east);
	if (cub->south)
		free_line(&cub->south);
	if (cub->west)
		free_line(&cub->west);
	if (cub->north)
		free_line(&cub->north);
	if (cub->line)
		free_line(&cub->line);
}

void	free_double_ptrs(t_cub3d *cub)
{
	if (cub->read)
		free_tab(&cub->read);
	if (cub->raw_args)
		free_tab(&cub->raw_args);
	if (cub->raw_map)
		free_tab(&cub->raw_map);
	if (cub->map)
		free_tab(&cub->map);
	if (cub->err_msg)
		free_tab(&cub->err_msg);
}

void	free_stack(t_cub3d *cub)
{
	t_xy	*tmp;
	t_xy	*aux;

	tmp = cub->stack;
	if (!tmp)
		return ;
	while (tmp)
	{
		aux = tmp;
		tmp = tmp->next;
		free(aux);
		aux = NULL;
	}
	cub->stack = NULL;
}
