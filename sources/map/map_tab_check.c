/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:16:28 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 11:57:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_check(int **tab, int height, int width)
{
	int	i;
	int	*prev;
	int	*next;

	i = 0;
	while (tab[i])
	{
		prev = NULL;
		next = NULL;
		if (i > 0)
			prev = tab[i - 1];
		if (i < height)
			next = tab[i + 1];
		if (map_tab_check_line(tab[i], prev, next, width) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}
