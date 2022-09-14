/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 15:42:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculate_step(t_game *game)
{
	//calculate step and initial sideDist
	if (game->ray_dirX < 0)
	{
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
	}
	else
	{
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
	}
	if (game->ray_dirY < 0)
	{
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
	}
	else
	{
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->deltaDistY;
	}
}
