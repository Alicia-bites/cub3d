/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_fullspace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:50:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 18:35:44 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_fullspace(t_mlx *mlx, t_ulist *obj)
{
	t_map_fd	*map;
	size_t		len;
	int			i;

	map = (t_map_fd *)obj->content;
	len = ft_strlen(map->line);
	i = 0;
	while (map->line[i] && ft_isspace(map->line[i]))
		i++;
	if (i == (int)len)
	{
		if (mlx->settings.map_start_line_no >= 0)
			return (ft_panic_value(-1, __func__,
					ERR_MAP_SPACE_IN, -1));
		else
			return (1);
	}
	return (0);
}
