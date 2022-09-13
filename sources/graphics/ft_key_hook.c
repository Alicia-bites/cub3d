/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/13 11:18:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_camera(t_game *game, int keycode)
{
	(void)game;
	if (keycode == CAM_RIGHT)
		NULL;
	else if (keycode == CAM_LEFT)
		NULL;
}

void ft_render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_image,
		game->player_x, game->player_y);
}

// void	move_player(int keycode, t_mlx *mlx)
// {
// 	printf("key = %d\n", keycode);
// 	// Move forward if no wall is in front of you
// 	if (keycode == UP)
// 	{	
// 		printf("game->vec.posX = %f\n", game->vec.posX);
// 		printf("game->vec.posY = %f\n", game->vec.posY);
// 		printf("game->vec.dirX = %f\n", game->vec.dirX);
// 		printf("game->vec.dirY = %f\n", game->vec.dirY);
// 		printf("(int)(game->vec.posX + game->vec.dirX) = %d\n", 
// 			(int)(game->vec.posX + game->vec.dirX));
// 		printf("(int)game->vec.posY = %d\n", (int)game->vec.posY);
// 		if (get_character_in_map(game->map, (int)(game->vec.posX + game->vec.dirX), (int)game->vec.posY) == '0')
// 			game->vec.posX += game->vec.dirX * MOVESPEED;
// 		if (get_character_in_map(game->map, (int)game->vec.posX, (int)(game->vec.posY + game->vec.dirY)) == '0')
// 			game->vec.posY += game->vec.dirY * MOVESPEED;
// 	}
// 	//move backwards if no wall behind you
// 	else if (keycode == DOWN)
// 	{
// 		if (get_character_in_map(game->map, (int)(game->vec.posX - game->vec.dirX), (int)game->vec.posY) == '0')
// 			game->vec.posX -= game->vec.dirX * MOVESPEED;
// 		if (get_character_in_map(game->map, (int)game->vec.posX, (int)(game->vec.posY - game->vec.dirY)) == '0')
// 			game->vec.posY -= game->vec.dirY * MOVESPEED;
// 	}
// 	//rotate to the right
// 	else if (keycode == RIGHT)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		game->vec.old_dirX = game->vec.dirX;
// 		game->vec.dirX = game->vec.dirX * cos(-ROTSPEED) - game->vec.dirY * sin(-ROTSPEED);
// 		game->vec.dirY = game->vec.old_dirX * sin(-ROTSPEED) + game->vec.dirY * cos(-ROTSPEED);
// 		game->vec.old_planeX = game->vec.planeX;
// 		game->vec.planeX = game->vec.planeX * cos(-ROTSPEED) - game->vec.planeY * sin(-ROTSPEED);
// 		game->vec.planeY = game->vec.old_planeX  * sin(-ROTSPEED) + game->vec.planeY * cos(-ROTSPEED);
// 	}
// 	//rotate to the left
// 	else if (keycode == LEFT)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		game->vec.old_dirX = game->vec.dirX;
// 		game->vec.dirX = game->vec.dirX  * cos(ROTSPEED) - game->vec.dirY * sin(ROTSPEED);
// 		game->vec.dirY = game->vec.old_dirX  * sin(ROTSPEED) + game->vec.dirY * cos(ROTSPEED);
// 		game->vec.old_planeX = game->vec.planeX;
// 		game->vec.planeX = game->vec.planeX * cos(ROTSPEED) - game->vec.planeY * sin(ROTSPEED);
// 		game->vec.planeY = game->vec.old_planeX * sin(ROTSPEED) + game->vec.planeY * cos(ROTSPEED);
// 	}
// }

// define how player move around
int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode != ESC_KEYCODE)
	{	
		if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		{
			// move_player(keycode, mlx);
			keypress(keycode, game);
		}
	}
	else
		ft_redcross(game, 0);
	
	return (keycode);
}

int	keypress(int keycode, t_game *game)
{
	extern int	worldMap[24][24];
	
	printf("pos_x == %f\n", (game->vec.posX));
	if (keycode == UP) // UP
	{
		if(worldMap[(int)(game->vec.posX + game->vec.dirX * MOVESPEED)][(int)game->vec.posY] == 0)
			game->vec.posX += game->vec.dirX * MOVESPEED;
		if(worldMap[(int)(game->vec.posX)][(int)(game->vec.posY + game->vec.dirY * MOVESPEED)] == 0)
			game->vec.posY += game->vec.dirY * MOVESPEED;
	}
	if (keycode == DOWN) // DOWN
	{
		if(worldMap[(int)(game->vec.posX - game->vec.dirX * MOVESPEED)][(int)game->vec.posY] == 0)
			game->vec.posX -= game->vec.dirX * MOVESPEED;
		if(worldMap[(int)(game->vec.posX)][(int)(game->vec.posY - game->vec.dirY * MOVESPEED)] == 0)
			game->vec.posY -= game->vec.dirY * MOVESPEED;
	}
	if (keycode == RIGHT)
    {
      //both camera direction and camera plane must be rotated
		game->vec.old_dirX = game->vec.dirX;
		game->vec.dirX = game->vec.dirX * cos(-ROTSPEED) - game->vec.dirY * sin(-ROTSPEED);
		game->vec.dirY = game->vec.old_dirX * sin(-ROTSPEED) + game->vec.dirY * cos(-ROTSPEED);
		game->vec.old_planeX = game->vec.planeX;
		game->vec.planeX = game->vec.planeX * cos(-ROTSPEED) - game->vec.planeY * sin(-ROTSPEED);
		game->vec.planeY = game->vec.old_planeX * sin(-ROTSPEED) + game->vec.planeY * cos(-ROTSPEED);
    }
	if (keycode == LEFT)
    {
      //both camera direction and camera plane must be rotated
		game->vec.old_dirX = game->vec.dirX;
		game->vec.dirX = game->vec.dirX * cos(ROTSPEED) - game->vec.dirY * sin(ROTSPEED);
		game->vec.dirY = game->vec.old_dirX * sin(ROTSPEED) + game->vec.dirY * cos(ROTSPEED);
		game->vec.old_planeX = game->vec.planeX;
		game->vec.planeX = game->vec.planeX * cos(ROTSPEED) - game->vec.planeY * sin(ROTSPEED);
		game->vec.planeY = game->vec.old_planeX * sin(ROTSPEED) + game->vec.planeY * cos(ROTSPEED);
    }	
	return (0);
}