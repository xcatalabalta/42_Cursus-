/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:57 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 08:36:38 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_exit(t_cub3d *cub, char *msg)
{
	int		i;
	char	*ascii;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	while (cub && cub->err_msg && cub->err_msg[i])
	{
		ft_putstr_fd("Info ", 2);
		ascii = ft_itoa(i);
		ft_putstr_fd(ascii, 2);
		free(ascii);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(cub->err_msg[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	free_all(cub);
}

int	set_error(t_cub3d *cub, char *msg)
{
	if (!msg || ft_strlen(msg) == 0)
		return (0);
	if (!push_line_to(cub, msg, &cub->err_msg))
		error_exit(cub, "Memory allocation error setting err_msg.");
	return (0);
}
