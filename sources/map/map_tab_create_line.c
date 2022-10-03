/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_create_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:52:53 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/03 14:18:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_create_line(t_map_fd *map, int *tab, int len_tab)
{
	size_t	len;
	int		i;

	len = ft_strlen(map->line);
	i = 0;
	while (i < (int)len)
	{
		tab[i] = (int)map->line[i];
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
