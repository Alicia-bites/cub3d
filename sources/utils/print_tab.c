/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:09:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/29 12:04:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

void	cyan()
{
	printf("\033[0;36m");
}

void	green()
{
	printf("\033[0;32m");
}

void	blue()
{
	printf("\033[0;34m");
}

void	purple()
{
	printf("\033[1;35m");
}

void	reset ()
{
	printf("\033[0m");
}

void	seagreen4()
{
	printf(SEAGREEN4);
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
			if (worldMap[i][j] == 1)
				cyan();
			else if (worldMap[i][j] == 0)
				green();
			else if (worldMap[i][j] < -1 && worldMap[i][j] > -6)
				purple();
			else if (worldMap[i][j] == -1)
				seagreen4();
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
