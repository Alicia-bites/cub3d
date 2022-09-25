/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:50:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 09:58:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_create(t_game *game, t_ulist *map_obj)
{
	t_ulist		*obj;
	t_map_fd	*map;
	int			i;

	obj = map_obj;
	map = (t_map_fd *)obj->content;
	i = 0;
	while (obj && map->line_no <= game->settings.map_end_line_no)
	{
		map_tab_create_line(map, game->map_tab[i],
			game->settings.map_width);
		obj = obj->next;
		if (obj)
			map = (t_map_fd *)obj->content;
		i++;
	}
	return (0);
}
