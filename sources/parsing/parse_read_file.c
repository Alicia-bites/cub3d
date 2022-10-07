/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/07 09:38:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_read_file(t_game *game)
{
	char		*line;
	int			line_no;
	t_map_fd	*map_fd_node;

	line_no = 1;
	while (42)
	{
		line = get_next_line(game->map_fd);
		if (!line)
			break ;
		map_fd_node = parse_map_fd_init(line_no, line);
		if (map_fd_node == NULL)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		if (ft_lst_append(game->map_fd_lst, (void *)map_fd_node) == NULL)
		{
			parse_map_fd_free((void *)map_fd_node);
			return (EXIT_FAILURE);
		}
		line_no++;
	}
	return (0);
}
