/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:34:20 by antho             #+#    #+#             */
/*   Updated: 2022/09/13 21:45:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_shiftbuf(char *buf)
{
	char	*nl;
	size_t	inl;

	nl = gnl_strchr(buf, '\n');
	inl = 0;
	if (nl == 0)
		buf[0] = '\0';
	else
	{
		inl = gnl_strlen(buf);
		gnl_strncpy(buf, &buf[inl], (size_t)BUFFER_SIZE);
	}
}

static void	gnl_eof(char *line)
{
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
	}
}

static char	*gnl_line(int fd, char *buf)
{
	char	*line;
	ssize_t	letters;

	line = 0;
	letters = 0;
	line = gnl_strjoin(line, buf);
	while (!gnl_strchr(buf, '\n'))
	{
		letters = read(fd, buf, (size_t)BUFFER_SIZE);
		if (letters <= 0)
			break ;
		buf[letters] = '\0';
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

static char	*gnl_start(int fd)
{
	static char	buf[BUFFER_SIZE];
	char	*line;

	line = gnl_line(fd, buf);
	if (!line || line[0] == '\0')
	{
		gnl_eof(line);
		line = 0;
	}
	else
		gnl_shiftbuf(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (0);
	line = gnl_start(fd);
	return (line);
}
