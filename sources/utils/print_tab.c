/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:09:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:32:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

static void	pick_color(int **worldMap, int i, int j)
{
	if (worldMap[i][j] == 1)
		cyan();
	else if (worldMap[i][j] == 0)
		green();
	else if (worldMap[i][j] < -1 && worldMap[i][j] > -6)
		purple();
	else if (worldMap[i][j] == -1)
		seagreen4();
}

//FOR DEBUG
void	print_tab(int **worldMap, int map_width, int map_height)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_height)
	{
		j = 0;
		printf(("{"));
		while (j < map_width)
		{
			pick_color(worldMap, i, j);
			if (worldMap[i][j] >= 0)
				printf(" ");
			printf("%d,", worldMap[i][j]);
			j++;
		}
		i++;
		reset();
		printf(("}"));
		printf(("\n"));
	}
}
