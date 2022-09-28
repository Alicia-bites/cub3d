/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:59:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 14:34:02 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	choose_wall_color(t_game *game)
{
	// extern int	worldMap[24][24];
	// printf("game->mapX = %d\n", game->mapX);
	// printf("game->mapY = %d\n", game->mapX);
		if (game->map_tab[game->mapY][game->mapX] == 1)
			game->color = 0x006EF0;
		else if (game->map_tab[game->mapY][game->mapX] == 2)
			game->color = 0xCBF018;
		else if (game->map_tab[game->mapY][game->mapX] == 3)
			game->color = 0x89A308;
		else if (game->map_tab[game->mapY][game->mapX] == 4)
			game->color = 0xF02C18;
		else
			game->color = 0x1052A3;
		//give x and y sides different brightness
		if (game->side == 1)
			game->color = game->color / 2;
	return (0);
}
