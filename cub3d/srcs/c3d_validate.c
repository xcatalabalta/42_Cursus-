/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:37:35 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/11 17:12:50 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate(t_cub3d *cub)
{
	int	i;

	if (!validate_args(cub))
		return (set_error(cub, "Invalid args."));
	if (!validate_map(cub))
		return (set_error(cub, "Invalid map."));
	i = 0;
	while (cub->map[i])
	{
		replace_chars(&cub->map[i], '0', '1');
		replace_chars(&cub->map[i++], '8', '0');
	}
	cub->map[cub->py][cub->px] = cub->po;
	printf("Success: valid map.\n");
	return (1);
}
