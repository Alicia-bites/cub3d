/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/02 16:36:02 by amarchan         ###   ########.fr       */
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



void	ft_clear_player(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->no_player_image,
		mlx->player_x, mlx->player_y);
}

void ft_render_player(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player_image, mlx->player_x, mlx->player_y);
}

void	move_player(t_mlx *mlx, int keycode)
{
	if (keycode == UP)
		mlx->player_y -= 64;
	else if (keycode == DOWN)
		mlx->player_y += 64;
	else if (keycode == LEFT)
		mlx->player_x -= 64;
	else if (keycode == RIGHT)
		mlx->player_x += 64;
}

//define how player move around
int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode != ESC_KEYCODE)
	{	
		if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		{
			ft_clear_player(mlx);
			move_player(mlx, keycode);
			ft_render_player(mlx);
		}
	}
	else
		ft_redcross(mlx, 0);
	return (keycode);
}
