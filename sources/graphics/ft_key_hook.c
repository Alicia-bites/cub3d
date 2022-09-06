/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 16:36:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_camera(t_mlx *mlx, int keycode)
{
	(void)mlx;
	if (keycode == CAM_RIGHT)
		NULL;
	else if (keycode == CAM_LEFT)
		NULL;
}

void ft_render_player(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player_image,
		mlx->player_x, mlx->player_y);
}

void	move_player(int keycode, t_mlx *mlx)
{
	printf("key = %d\n", keycode);
	// Move forward if no wall is in front of you
	if (keycode == UP)
	{	
		printf("mlx->vec.posX = %f\n", mlx->vec.posX);
		printf("mlx->vec.posY = %f\n", mlx->vec.posY);
		printf("mlx->vec.dirX = %f\n", mlx->vec.dirX);
		printf("mlx->vec.dirY = %f\n", mlx->vec.dirY);
		printf("(int)(mlx->vec.posX + mlx->vec.dirX) = %d\n", 
			(int)(mlx->vec.posX + mlx->vec.dirX));
		printf("(int)mlx->vec.posY = %d\n", (int)mlx->vec.posY);
		if (get_character_in_map(mlx->map, (int)(mlx->vec.posX + mlx->vec.dirX), (int)mlx->vec.posY) == '0')
			mlx->vec.posX += mlx->vec.dirX * MOVESPEED;
		if (get_character_in_map(mlx->map, (int)mlx->vec.posX, (int)(mlx->vec.posY + mlx->vec.dirY)) == '0')
			mlx->vec.posY += mlx->vec.dirY * MOVESPEED;
	}
	//move backwards if no wall behind you
	else if (keycode == DOWN)
	{
		if (get_character_in_map(mlx->map, (int)(mlx->vec.posX - mlx->vec.dirX), (int)mlx->vec.posY) == '0')
			mlx->vec.posX -= mlx->vec.dirX * MOVESPEED;
		if (get_character_in_map(mlx->map, (int)mlx->vec.posX, (int)(mlx->vec.posY - mlx->vec.dirY)) == '0')
			mlx->vec.posY -= mlx->vec.dirY * MOVESPEED;
	}
	//rotate to the right
	else if (keycode == RIGHT)
	{
		//both camera direction and camera plane must be rotated
		mlx->vec.old_dirX = mlx->vec.dirX;
		mlx->vec.dirX = mlx->vec.dirX * cos(-ROTSPEED) - mlx->vec.dirY * sin(-ROTSPEED);
		mlx->vec.dirY = mlx->vec.old_dirX * sin(-ROTSPEED) + mlx->vec.dirY * cos(-ROTSPEED);
		mlx->vec.old_planeX = mlx->vec.planeX;
		mlx->vec.planeX = mlx->vec.planeX * cos(-ROTSPEED) - mlx->vec.planeY * sin(-ROTSPEED);
		mlx->vec.planeY = mlx->vec.old_planeX  * sin(-ROTSPEED) + mlx->vec.planeY * cos(-ROTSPEED);
	}
	//rotate to the left
	else if (keycode == LEFT)
	{
		//both camera direction and camera plane must be rotated
		mlx->vec.old_dirX = mlx->vec.dirX;
		mlx->vec.dirX = mlx->vec.dirX  * cos(ROTSPEED) - mlx->vec.dirY * sin(ROTSPEED);
		mlx->vec.dirY = mlx->vec.old_dirX  * sin(ROTSPEED) + mlx->vec.dirY * cos(ROTSPEED);
		mlx->vec.old_planeX = mlx->vec.planeX;
		mlx->vec.planeX = mlx->vec.planeX * cos(ROTSPEED) - mlx->vec.planeY * sin(ROTSPEED);
		mlx->vec.planeY = mlx->vec.old_planeX * sin(ROTSPEED) + mlx->vec.planeY * cos(ROTSPEED);
	}
}

//define how player move around
int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode != ESC_KEYCODE)
	{	
		if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		{
			move_player (keycode, mlx);
		}
	}
	else
		ft_redcross(mlx, 0);
	
	return (keycode);
}
