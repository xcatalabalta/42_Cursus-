/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:56:59 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/22 12:16:58 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_pathname(t_cub3d *cub, char *pname, char *ext)
{
	int	len;

	len = ft_strlen(pname);
	if (!pname || len < 5)
		return (set_error(cub, "Wrong pathname length."));
	if (ft_strncmp(pname + len - 4, ext, 4) != 0)
		return (set_error(cub, "Invalid file extension."));
	cub->i = 0;
	while (xy_iterator(NULL, 0, &cub->i, len - 4))
	{
		if (!ft_isalnum(pname[cub->i]) && !ft_strchr("_-./", pname[cub->i]))
			return (set_error(cub, "Invalid char in pathname."));
	}
	return (1);
}

int	replace_chars(char **line, char ori, char rep)
{
	int	i;

	i = -1;
	while (xy_iterator(NULL, 0, &i, ft_strlen(*line)))
		if ((*line)[i] == ori)
			(*line)[i] = rep;
	return (1);
}

int	clean_redundant_spaces(char **line)
{
	int	prev_was_space;
	int	i;
	int	j;

	i = 0;
	j = 0;
	prev_was_space = 0;
	while (line && (*line) && (*line)[i])
	{
		if ((*line)[i] == ' ' && (prev_was_space || (*line)[i + 1] == ' '))
			i++;
		else
		{
			prev_was_space = (*line)[i] == ' ';
			(*line)[j++] = (*line)[i++];
		}
	}
	(*line)[j] = '\0';
	return (1);
}

int	push_line_to(t_cub3d *cub, char *line, char ***dest)
{
	char	**tmp;
	int		tab_len;

	if (!line || ft_strlen(line) == 0)
		return (1);
	tab_len = ft_tablen(*dest);
	tmp = realloc(*dest, sizeof(char *) * (tab_len + 2));
	if (!tmp)
		return (set_error(cub, "Realloc error (push_line_to)."));
	*dest = tmp;
	(*dest)[tab_len] = ft_strdup(line);
	if (!(*dest)[tab_len])
		return (set_error(cub, "Malloc error (push_line_to)"));
	(*dest)[tab_len + 1] = NULL;
	return (1);
}

void	replace_tabs(t_cub3d *cub, char **line)
{
	int		x;
	int		i;
	int		len;
	char	*tmp;

	x = 0;
	while ((*line)[x])
	{
		if ((*line)[x] == '\t')
		{
			len = (int)ft_strlen(*line);
			tmp = realloc(*line, len + 4);
			if (!tmp)
				error_exit(cub, "Realloc error (replace_tabs).");
			*line = tmp;
			ft_memmove(&(*line)[x + 4], &(*line)[x + 1], len - x);
			i = 0;
			while (i < 4)
				(*line)[x + i++] = ' ';
			x += 3;
			(*line)[len + 3] = '\0';
		}
		x++;
	}
}
