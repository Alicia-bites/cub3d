/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 11:17:45 by abarrier         ###   ########.fr       */
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
	if (main_init_conf_game(argc, argv, &game) != 0)
		return (EXIT_FAILURE);
	err = init_game(&game);
	clean_up(&game, err);
	map_tab_free(game.map_tab);
	settings_free(&game.settings);
	ft_lst_free(game.map_fd_lst, &parse_map_fd_free);
	if (err)
		return (err);
	else
		return (0);
}
