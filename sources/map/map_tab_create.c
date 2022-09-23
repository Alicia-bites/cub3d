/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:50:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 17:59:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_create(t_mlx *mlx, t_ulist *map_obj)
{
	t_ulist		*obj;
	t_map_fd	*map;
	int			i;

	obj = map_obj;
	map = (t_map_fd *)obj->content;
	i = 0;
	while (obj && map->line_no <= mlx->settings.map_end_line_no)
	{
		map = (t_map_fd *)obj->content;
		map_tab_create_line(map, mlx->map_tab[i],
			mlx->settings.map_width);
		obj = obj->next;
		i++;
	}
	return (0);
}
