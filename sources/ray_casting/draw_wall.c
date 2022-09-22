/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:56:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/22 15:57:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_wall(t_game *game)
{
    // Calculate distance projected on camera direction (Euclidean 
	// distance would give fisheye effect!)
	if (game->side == 0) 
		game->perpWallDist = (game->mapX - game->posX + (1 - game->stepX) / 2) / game->ray_dirX;
	else          
		game->perpWallDist = (game->mapY - game->posY + (1 - game->stepY) / 2) / game->ray_dirY;
	//calculate height of line to draw on screen
	game->lineHeight = (int)(WINDOW_HEIGHT / game->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	game->drawStart = -(game->lineHeight) / 2 + WINDOW_HEIGHT / 2;
	if(game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if(game->drawEnd >= WINDOW_HEIGHT)
		game->drawEnd = WINDOW_HEIGHT - 1;
	return (0);
}

