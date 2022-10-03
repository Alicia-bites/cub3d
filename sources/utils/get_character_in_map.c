/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_character_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:03:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:20:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	get_character_in_map(t_list *map, int x, int y)
{
	int	i;

	i = 0;
	while (map)
	{
		if (map->index == y)
		{
			while (map->line)
			{
				if (i == x)
					return (map->line[x]);
				i++;
			}
		}
		map = map->next;
	}
	return (CHAR_NOT_FOUND);
}
