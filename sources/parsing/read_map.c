/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:41:16 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 12:26:10 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	wrong_file(char *str)
{
	int	l;

	l = ft_strlen(str) - 1;
	if (str[l] != 'b' || str[l - 1] != 'u'
		|| str[l - 2] != 'c' || str[l - 3] != '.')
		return (1);
	return (0);
}

t_list	*read_map(char *argv)
{
	int		fd;
	t_list	*lst;
	char	*line;

	if (wrong_file(argv))
	{
		ft_putstr_fd("Error\nWrong type of file or empty file.\n", 2);
		exit (FILE_ERROR);
	}
	fd = open(argv, O_RDONLY, __O_NOFOLLOW);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_putstr_fd("Error\nWrong type of file or empty file.\n", 2);
		exit(FILE_ERROR);
	}
	while (line != NULL)
	{
		lst = create_list(line);
		line = get_next_line(fd);
	}
	return (lst);
}
