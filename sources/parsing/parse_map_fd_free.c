/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_fd_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:04 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 17:13:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_map_fd_free(void *content)
{
	t_map_fd	*map_fd_node;

	if (!content)
		return ;
	map_fd_node = (t_map_fd *)content;
	if (map_fd_node->line)
	{
		free(map_fd_node->line);
		map_fd_node->line = NULL;
	}
	if (map_fd_node)
	{
		free(map_fd_node);
		map_fd_node = NULL;
	}
}
