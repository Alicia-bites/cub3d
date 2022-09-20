/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/20 12:31:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	print_tab(int worldMap[24][24], int map_width, int map_height)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map_height)
// 	{
// 		j = 0;
// 		printf(("{"));
// 		while (j < map_width)
// 		{
// 			printf("%d,", worldMap[i][j]);
// 			j++;
// 		}
// 		i++;
// 		printf(("}"));
// 		printf(("\n"));
// 	}
// }

int	main(int argc, char **argv)
{
	t_game	game;
	int		*map;
		
	// cb_mlx_init(&mlx);
	// cb_mlx_show(&mlx);
	map = NULL;
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Oups, wrong number of arguments!", 2);
		return (-1);
	}
  game.map = map;
	// print_tab(worldMap, mapWIDTH, mapHeight);
	init_game(&game);
	return (0);
}
