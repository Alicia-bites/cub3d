/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_start_and_end_of_line.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:56:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:11:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Calculate distance projected on camera direction (Euclidean 
// distance would give fisheye effect!)
int	calculate_start_and_end_of_line(t_game *game)
{
	if (game->side == 0)
		game->perpWallDist = (game->mapX - game->posX + (1 - game->stepX) / 2)
			/ game->ray_dirX;
	else
		game->perpWallDist = (game->mapY - game->posY + (1 - game->stepY) / 2)
			/ game->ray_dirY;
	game->lineHeight = (int)(WINDOW_HEIGHT / game->perpWallDist);
	game->drawStart = -(game->lineHeight) / 2 + WINDOW_HEIGHT / 2;
	if (game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (game->drawEnd >= WINDOW_HEIGHT)
		game->drawEnd = WINDOW_HEIGHT - 1;
	return (0);
}
