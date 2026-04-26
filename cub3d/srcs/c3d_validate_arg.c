/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:21:25 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 09:47:42 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_args(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->raw_args[i])
	{
		if (cub->raw_args[i][0] == 'E' || cub->raw_args[i][0] == 'S'
			|| cub->raw_args[i][0] == 'W' || cub->raw_args[i][0] == 'N')
		{
			if (!texture_process(cub, cub->raw_args[i]))
				return (set_error(cub, "Invalid texture arg."));
		}
		else if (cub->raw_args[i][0] == 'C' || cub->raw_args[i][0] == 'F')
		{
			if (!rgb_process(cub, cub->raw_args[i]))
				return (set_error(cub, "Invalid rgb arg."));
		}
		i++;
	}
	return (1);
}
