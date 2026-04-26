/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:06:43 by mvisca            #+#    #+#             */
/*   Updated: 2024/07/22 11:47:57 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	builtin_pwd(t_ms *ms)
{
	char	path[MAX_PATH];

	getcwd(path, sizeof(path));
	if (ft_strlenp(path))
		ft_printf("%s\n", path);
	else
		ft_printf("%s\n", environment_get_value(ms, "PWD"));
	return (0);
}
