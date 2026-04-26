/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_free1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:50:11 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 08:38:34 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	if (tab && *tab)
	{
		while ((*tab)[i])
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			i++;
		}
	}
	free((*tab)[i]);
	if (tab && *tab)
	{
		free(*tab);
		*tab = NULL;
	}
}

void	free_line(char **line)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
}

void	free_all(t_cub3d *cub)
{
	free_ptrs(cub);
	free_double_ptrs(cub);
	free_stack(cub);
	printf("Exit Success.\n");
	exit(EXIT_SUCCESS);
}
