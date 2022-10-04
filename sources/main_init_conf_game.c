/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init_conf_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 07:02:08 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/04 07:13:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main_init_conf_game(int argc, char **argv, t_game *game)
{
	if (parse(argc, argv, game) != 0)
	{
		settings_free(&game->settings);
		ft_lst_free(game->map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (settings_check(&game->settings) != 0)
	{
		settings_free(&game->settings);
		ft_lst_free(game->map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	if (map(game) != 0)
	{
		map_tab_free(game);
		settings_free(&game->settings);
		ft_lst_free(game->map_fd_lst, &parse_map_fd_free);
		return (EXIT_FAILURE);
	}
	return (0);
}
