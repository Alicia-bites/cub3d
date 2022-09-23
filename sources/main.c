/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/23 17:34:22 by abarrier         ###   ########.fr       */
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
//	t_game  game;
//	int     *map;
	t_mlx	mlx;
	t_ulist	**map_fd_lst;
	
	cb_mlx_init(&mlx);
	//cb_mlx_show(&mlx);
	map_fd_lst = ft_lst_init();
	if (!map_fd_lst )
		return (EXIT_FAILURE);
	mlx.map_fd_lst = map_fd_lst;
	settings_show(&mlx.settings);
	if (parse(argc, argv, &mlx) != 0)
	{
		settings_free(&mlx.settings);
		ft_lst_free(mlx.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (settings_check(&mlx.settings) != 0)
	{
		settings_free(&mlx.settings);
		ft_lst_free(mlx.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (map(&mlx) != 0)
	{
		map_tab_free(&mlx);
		settings_free(&mlx.settings);
		ft_lst_free(mlx.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	settings_show(&mlx.settings);
	map_tab_free(&mlx);
	settings_free(&mlx.settings);
	ft_lst_free(mlx.map_fd_lst, &parse_map_fd_free);
//	ft_lst_func_lst(mlx.map_fd_lst, &parse_map_fd_show);
//	map = NULL;
//	if (argc != 2)
//	{
//		ft_putstr_fd("Oups, wrong number of arguments!", 2);
//		return (-1);
//	}
//	game.map = map;
//	// print_tab(worldMap, mapWIDTH, mapHeight);
//	init_game(&game);
return (0);
}
