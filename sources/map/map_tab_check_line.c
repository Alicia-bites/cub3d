/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_check_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:26:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 11:58:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_check_line(int *line, int *prev, int *next, int width)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			 || line[i] == 'E' || line[i] == 'W')
		{
			if (map_tab_check_line_horizontal(line, i, -1,
				width) != 0)
				return (EXIT_FAILURE);
			if (map_tab_check_line_horizontal(line, i, 1,
				width) != 0)
				return (EXIT_FAILURE);
			if (map_tab_check_line_vertical(prev, i) != 0)
				return (EXIT_FAILURE);
			if (map_tab_check_line_vertical(next, i) != 0)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
