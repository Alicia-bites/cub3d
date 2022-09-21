/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:42:30 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 09:32:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cb_mlx_show(t_mlx *mlx)
{
	printf("map ptr: %p\n", mlx->map);
	printf("map fd: %d\n", mlx->map_fd);
	printf("settings ptr: %p\n", &mlx->settings);
	printf("image | height: %d\twidth: %d\n", mlx->image_height,
		mlx->image_width);
	printf("row: %d\tcol: %d\n", mlx->row_width, mlx->col_height);
	printf("map | height: %d\twidth: %d\n", mlx->map_height,
		mlx->map_width);
	printf("sprite size: %d\n", mlx->sprite_size);
	printf("player | x: %d\ty: %d\n", mlx->player_x, mlx->player_y);
	printf("image ptr: %p\n", mlx->image);
	printf("mlx ptr: %p\n", mlx->mlx_ptr);
	printf("player ptr: %p\n", mlx->player);
	printf("win ptr: %p\n", mlx->win_ptr);
	printf("player image ptr: %p\n", mlx->player_image);
	printf("no player image ptr: %p\n", mlx->no_player_image);
	settings_show(&mlx->settings);
}
