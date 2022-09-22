/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_start_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:17:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 17:23:38 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_ulist	*map_get_start_obj(t_mlx *mlx)
{
	t_ulist		*obj;
	t_map_fd	*map;

	obj = *mlx->map_fd_lst;
	while (obj)
	{
		map = NULL;
		map = (t_map_fd *)obj->content;
		if (mlx->settings.map_start_line_no == map->line_no)
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}
