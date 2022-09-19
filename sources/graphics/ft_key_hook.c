/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 15:28:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	keypress(int keycode, t_game *game)
{
	extern int	worldMap[24][24];
	
	if (keycode == K_UP)
	{
		if(worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] == 0)
			game->posX += game->dirX * MOVESPEED;
		if(worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] == 0)
			game->posY += game->dirY * MOVESPEED;
	}
	if (keycode == K_DOWN)
	{
		if(worldMap[(int)(game->posX - game->dirX * MOVESPEED)][(int)game->posY] == 0)
			game->posX -= game->dirX * MOVESPEED;
		if(worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)] == 0)
			game->posY -= game->dirY * MOVESPEED;
	}
	if (keycode == K_RIGHT)
    {
      // Both camera direction and camera plane must be rotated
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos(-ROTSPEED) - game->dirY * sin(-ROTSPEED);
		game->dirY = game->oldDirX * sin(-ROTSPEED) + game->dirY * cos(-ROTSPEED);
		game->oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(-ROTSPEED) - game->planeY * sin(-ROTSPEED);
		game->planeY = game->oldPlaneX * sin(-ROTSPEED) + game->planeY * cos(-ROTSPEED);
    }
	if (keycode == K_LEFT)
    {
      // Both camera direction and camera plane must be rotated
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos(ROTSPEED) - game->dirY * sin(ROTSPEED);
		game->dirY = game->oldDirX * sin(ROTSPEED) + game->dirY * cos(ROTSPEED);
		game->oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(ROTSPEED) - game->planeY * sin(ROTSPEED);
		game->planeY = game->oldPlaneX * sin(ROTSPEED) + game->planeY * cos(ROTSPEED);
    }
	if (keycode == ESC)
		exit(0);
	return (0);
}