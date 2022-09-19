/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_fd_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:17:39 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:24:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_map_fd_show(void *content)
{
	t_map_fd	*map_fd_node;

	if (!content)
		return ;
	map_fd_node = (t_map_fd *)content;
	printf("map_fd_node->line_no: %d\n", map_fd_node->line_no);
	if (map_fd_node->line)
		printf("map_fd_node->line: %s\n", map_fd_node->line);
	else
		printf("map_fd_node->line: NULL\n");

}
