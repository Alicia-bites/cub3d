/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_position_and_direction.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:10:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 15:40:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	calculate_ray_position_and_direction(t_game *game, int x)
{
	// calculate ray position and direction
	game->cameraX = 2.0 * (double)x / (double)game->width - 1.0;
	game->ray_dirX = game->dirX + game->planeX * game->cameraX;
	game->ray_dirY = game->dirY + game->planeY * game->cameraX;
	//which box of the map we're in
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
	//--> to see if a wall was hit :
	game->hit = 0;
	//length of ray from one x-side to next x-side
	if (game->ray_dirX == 0.0)
		game->deltaDistX = 1e30;
	else
		game->deltaDistX = fabs(1.0 / game->ray_dirX);
	//length of ray from one y-side to next y-side
	if (game->ray_dirY == 0.0)
		game->deltaDistY = 1e30;
	else
		game->deltaDistY = fabs(1.0 / game->ray_dirY);
	return (0);
}
