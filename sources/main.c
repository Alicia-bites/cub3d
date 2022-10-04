/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 17:13:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_ulist	**map_fd_lst;
	int		err;

	err = 0;
	main_init_map(&game);
	map_fd_lst = ft_lst_init();
	if (!map_fd_lst)
		return (EXIT_FAILURE);
	game.map_fd_lst = map_fd_lst;
	main_init_conf_game(argc, argv, &game);
	print_tab(game.map_tab, game.settings.map_width, game.settings.map_height);
	err = init_game(&game);
	map_tab_free(&game);
	settings_free(&game.settings);
	ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
	if (err)
		return (err);
	else
		return (0);
}
