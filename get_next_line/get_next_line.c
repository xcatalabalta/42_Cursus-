/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:57:43 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 10:39:59 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 500
*/
#include "get_next_line.h"

static char	*ft_readfile(int fd, char *stat)
{
	char	*buff;
	int		lu;
	char	*tmp;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_clean(&stat));
	buff[0] = '\0';
	lu = 1;
	while (lu > 0 && !ft_strchr(stat, 10))
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu > 0)
		{
			buff[lu] = '\0';
			tmp = ft_strjoin(stat, buff);
			free(stat);
			stat = tmp;
		}
	}
	free (buff);
	if (lu < 0)
		return (ft_clean(&stat));
	return (stat);
}

static char	*ft_extract_line(char *stat)
{
	char	*line;
	size_t	len;

	len = ft_strlen(stat) - ft_strlen(ft_strchr(stat, 10)) + 1;
	line = ft_substr(stat, 0, len);
	if (!line)
		return (ft_clean(&line));
	return (line);
}

static char	*ft_update(char *stat)
{
	char	*new_stat;
	size_t	len;

	if (!ft_strchr(stat, 10))
		return (ft_clean(&stat));
	len = ft_strlen(stat) - ft_strlen(ft_strchr(stat, 10)) + 1;
	if (stat[len] == '\0')
		return (ft_clean(&stat));
	new_stat = ft_substr(stat, len, ft_strlen(stat) - len);
	ft_clean(&stat);
	if (!new_stat)
		return (ft_clean(&new_stat));
	return (new_stat);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stat = ft_readfile(fd, stat);
	if (!stat)
		return (NULL);
	line = ft_extract_line(stat);
	if (!line)
		return (ft_clean(&stat));
	stat = ft_update(stat);
	return (line);
}
