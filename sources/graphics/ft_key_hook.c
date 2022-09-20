/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/20 12:26:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_up(t_game *game)
{
	extern int worldMap[24][24];
	
	if(worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX += game->dirX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] == 0)
		game->posY += game->dirY * MOVESPEED;
}

void	move_down(t_game *game)
{
	extern int worldMap[24][24];
	
	if(worldMap[(int)(game->posX - game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX -= game->dirX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)] == 0)
		game->posY -= game->dirY * MOVESPEED;
}

void	move_right(t_game *game)
{
	if(worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX -= game->planeX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] == 0)
		game->posY -= game->planeY * MOVESPEED;
}

int	keypress(int keycode, t_game *game)
{
	extern int worldMap[24][24];	
	//move up
	if (keycode == K_W)
	{
		move_up(game);
	}
	//move down
	if (keycode == K_S)
	{
		move_down(game);
	}
	// move to the left
	if (keycode == K_A)
	{
		move_right(game);
	}
	// move to the right
	if (keycode == K_D)
	{
		if(worldMap[(int)(game->posX - game->dirX * MOVESPEED)][(int)game->posY] == 0)
			game->posX += game->planeX * MOVESPEED;
		if(worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)] == 0)
			game->posY += game->planeY * MOVESPEED;
	}
	// Rotate to the right
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
	// Rotate to the left
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