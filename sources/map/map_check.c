/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:27:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 13:48:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check(t_mlx *mlx, t_ulist *map_obj)
{
	t_ulist		*obj;
	t_map_fd	*map;

	obj = map_obj;
	map = (t_map_fd *)obj->content;
	while (obj && map->line_no <= mlx->settings.map_end_line_no)
	{
		map = (t_map_fd *)obj->content;
		if (map_check_line(&mlx->settings, map) != 0)
			return (EXIT_FAILURE);
		settings_rm_space_end(map->line);
		map_check_width(&mlx->settings, map->line);
		obj = obj->next;
	}
	return (0);
}
