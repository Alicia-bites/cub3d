/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 14:37:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check_line(t_settings *settings, t_map_fd *map)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map_check_line_char((int)map->line[i]) != 0)
			return (EXIT_FAILURE);
		if (map_check_line_player_sp(settings, (int)map->line[i],
				i, map->line_no) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}
