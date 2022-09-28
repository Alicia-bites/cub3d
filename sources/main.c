/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/28 09:39:20 by abarrier         ###   ########.fr       */
=======
/*   Updated: 2022/09/28 16:12:26 by amarchan         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game	game;
//	int		*map_test;
	t_ulist	**map_fd_lst;
	int		err;

<<<<<<< HEAD
//	map_test = NULL;
=======
	err = 0;
	map_test = NULL;
>>>>>>> main
	game.map_fd = FD_NOT_INIT;
	game.map_fd_lst = NULL;;
	game.map_tab = NULL;
	settings_init(&game.settings);
	map_fd_lst = ft_lst_init();
	if (!map_fd_lst )
		return (EXIT_FAILURE);
	game.map_fd_lst = map_fd_lst;
	// settings_show(&game.settings);
	if (parse(argc, argv, &game) != 0)
	{
		settings_free(&game.settings);
		ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (settings_check(&game.settings) != 0)
	{
		settings_free(&game.settings);
		ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (map(&game) != 0)
	{
		map_tab_free(&game);
		settings_free(&game.settings);
		ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	print_tab(game.map_tab, game.settings.map_width, game.settings.map_height);
	err = init_game(&game);
	if (err)
		return (err);
	// settings_show(&game.settings);
	map_tab_free(&game);
	settings_free(&game.settings);
	ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
//	ft_lst_func_lst(mlx.map_fd_lst, &parse_map_fd_show);
//	map_test = NULL;
//	if (argc != 2)
//	{
//		ft_putstr_fd("Oups, wrong number of arguments!", 2);
//		return (-1);
//	}
	// game.map = map_test;
	return (0);
}
