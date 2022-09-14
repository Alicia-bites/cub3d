/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:56:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 15:48:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_wall(t_game *game)
{
    // Calculate distance projected on camera direction (Euclidean 
	// distance would give fisheye effect!)
	if (game->side == 0) 
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else          
		game->perpWallDist = (game->sideDistY - game->deltaDistY);
	game->lineHeight = (int)(game->height / game->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	game->drawStart = -(game->lineHeight) / 2 + game->height / 2;
	if(game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + game->height / 2;
	if(game->drawEnd >= game->height)
		game->drawEnd = game->height - 1;
	return (0);
}

