/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_adjust_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:26:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/28 19:46:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_adjust_line(int *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
			line[i] = line[i] - '0';
		else if (line[i] == 'N')
			line[i] = N;
		else if (line[i] == 'E')
			line[i] = E;
		else if (line[i] == 'S')
			line[i] = S;
		else if (line[i] == 'W')
			line[i] = O;
		else if (line[i] == ' ')
			line[i] = SP;
		i++;
	}
}
