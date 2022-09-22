/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:27:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 18:08:53 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check_char(t_mlx *mlx, t_ulist *map_obj)
{
	t_ulist		*obj;
	t_map_fd	*map;

	obj = map_obj;
	map = (t_map_fd *)obj->content;
	while (obj && map->line_no <= mlx->settings.map_end_line_no)
	{
		if (map_check_char_line(map->line) != 0)
			return (EXIT_FAILURE);
		obj = obj->next;
		map = (t_map_fd *)obj->content;
	}
	return (0);
}
