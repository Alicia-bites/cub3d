/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 07:08:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/04 07:25:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	main_init_map(t_game *game)
{
	game->map_fd = FD_NOT_INIT;
	game->map_fd_lst = NULL;
	game->map_tab = NULL;
	settings_init(&game->settings);
}
