/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_fd_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:07:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:23:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_map_fd	*parse_map_fd_init(int line_no, char *line)
{
	t_map_fd	*map_fd;

	map_fd = NULL;
	map_fd = (t_map_fd *)malloc(sizeof(t_map_fd));
	if (!map_fd)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	map_fd->line_no = line_no;
	map_fd->line = line;
	return (map_fd);
}
