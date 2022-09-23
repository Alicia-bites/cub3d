/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_create_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:52:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 18:12:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_create_line(t_map_fd *map, int *tab, int len_tab)
{
	size_t	len;
	int		i;

	len = ft_strlen(map->line);
	printf("DEBUG: len_line: %zu\nlen tab: %d\n", len, len_tab);
	i = 0;
	while (i < (int)len)
	{
		tab[i] = map->line[i];
		i++;
	}
	while (i < len_tab)
	{
		tab[i] = ' ';
		i++;
	}
	tab[i] = '\0';
	return (0);
}
