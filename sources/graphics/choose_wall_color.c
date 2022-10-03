/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:59:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:40:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	choose_wall_color(t_game *game)
{
	if (game->map_tab[game->map_y][game->map_x] == 1)
		game->color = 0x006EF0;
	else if (game->map_tab[game->map_y][game->map_x] == 2)
		game->color = 0xCBF018;
	else if (game->map_tab[game->map_y][game->map_x] == 3)
		game->color = 0x89A308;
	else if (game->map_tab[game->map_y][game->map_x] == 4)
		game->color = 0xF02C18;
	else
		game->color = 0x1052A3;
	if (game->side == 1)
		game->color = game->color / 2;
	return (0);
}
