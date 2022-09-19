/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:25:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_read_file(t_mlx *mlx)
{
	char	*line;
	int	line_no;
	t_map_fd	*map_fd_node;

	line_no = 1;
	while (42)
	{
		line = NULL;
		map_fd_node = NULL;
		line = get_next_line(mlx->map_fd);
		if (!line)
			break ;
		map_fd_node = parse_map_fd_init(line_no, line);
		if (ft_lst_append(mlx->map_fd_lst, (void *)map_fd_node) == NULL)
		{
			ft_lst_free(mlx->map_fd_lst, &parse_map_fd_free);
			free(line);
			return ;
		}
		line_no++;
	}
}
