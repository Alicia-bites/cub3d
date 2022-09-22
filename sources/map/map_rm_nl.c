/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rm_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:27:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 18:16:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_rm_nl(t_mlx *mlx, t_ulist *map_obj)
{
	t_ulist		*obj;
	t_map_fd	*map;

	obj = map_obj;
	map = (t_map_fd *)obj->content;
	while (obj && map->line_no <= mlx->settings.map_end_line_no)
	{
		map = (t_map_fd *)obj->content;
		map_rm_nl_line(map->line);
		obj = obj->next;
	}
}
