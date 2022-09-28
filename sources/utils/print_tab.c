/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:09:09 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 16:09:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

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
			printf("%d,", worldMap[i][j]);
			j++;
		}
		i++;
		printf(("}"));
		printf(("\n"));
	}
}
