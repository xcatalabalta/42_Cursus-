/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:35:17 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/23 09:39:25 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	gnl_success(t_cub3d *cub)
{
	cub->line = get_next_line(cub->fd);
	if (cub->line)
		return (1);
	if (errno)
		return (set_error(cub, "Error reading file."));
	return (0);
}

static int	read_file(t_cub3d *cub)
{
	while (gnl_success(cub))
	{
		replace_chars(&cub->line, '\n', '\0');
		push_line_to(cub, cub->line, &cub->read);
		free(cub->line);
		cub->line = NULL;
	}
	return (1);
}

int	parse(t_cub3d *cub, char *pathname)
{
	if (!check_pathname(cub, pathname, ".cub"))
		return (set_error(cub, "Invalid pathname."));
	cub->fd = open(pathname, O_RDONLY);
	if (cub->fd < 0)
		return (set_error(cub, "Open file failed."));
	if (!read_file(cub))
		return (set_error(cub, "Read file failed."));
	if (close(cub->fd) < 0)
		return (set_error(cub, "Could not close file."));
	if (!read_process(cub))
		return (set_error(cub, "Failed to process read tab."));
	printf("Success: file parsed.\n");
	return (1);
}
