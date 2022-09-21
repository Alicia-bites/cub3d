/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 13:26:30 by amarchan         ###   ########.fr       */
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
	extern int worldMap[24][24];

	if(worldMap[(int)(game->posX - game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX += game->planeX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)] == 0)
		game->posY += game->planeY * MOVESPEED;

}

void	move_left(t_game *game)
{
	extern int	worldMap[24][24];
	
	if(worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX -= game->planeX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] == 0)
		game->posY -= game->planeY * MOVESPEED;

}

void	rotate_right(t_game *game)
{
	game->oldDirX = game->dirX;
	game->dirX = game->dirX * cos(-ROTSPEED) - game->dirY * sin(-ROTSPEED);
	game->dirY = game->oldDirX * sin(-ROTSPEED) + game->dirY * cos(-ROTSPEED);
	game->oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(-ROTSPEED) - game->planeY * sin(-ROTSPEED);
	game->planeY = game->oldPlaneX * sin(-ROTSPEED) + game->planeY * cos(-ROTSPEED);
}

void rotate_left(t_game *game)
{
	game->oldDirX = game->dirX;
	game->dirX = game->dirX * cos(ROTSPEED) - game->dirY * sin(ROTSPEED);
	game->dirY = game->oldDirX * sin(ROTSPEED) + game->dirY * cos(ROTSPEED);
	game->oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(ROTSPEED) - game->planeY * sin(ROTSPEED);
	game->planeY = game->oldPlaneX * sin(ROTSPEED) + game->planeY * cos(ROTSPEED);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == K_W)
		move_up(game);
	if (keycode == K_S)
		move_down(game);
	if (keycode == K_A)
		move_left(game);
	if (keycode == K_D)
		move_right(game);
	if (keycode == K_RIGHT)
		rotate_right(game);
	if (keycode == K_LEFT)
		rotate_left(game);
	if (keycode == ESC)
		exit(0);
	return (0);
}