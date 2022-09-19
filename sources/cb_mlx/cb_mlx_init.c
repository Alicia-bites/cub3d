/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:30:22 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 09:49:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cb_mlx_init(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->map_fd = -1;
	mlx->map_fd_lst = NULL;
	mlx->image_height = 0;
	mlx->image_width = 0;
	mlx->row_width = 0;
	mlx->col_height = 0;
	mlx->map_height = 0;
	mlx->map_width = 0;
	mlx->sprite_size = 0;
	mlx->player_x = 0;
	mlx->player_y = 0;
	mlx->image = NULL;
	mlx->mlx_ptr = NULL;
	mlx->player = NULL;
	mlx->win_ptr = NULL;
	mlx->player_image = NULL;
	mlx->no_player_image = NULL;
	cb_mlx_init_settings(&mlx->settings);
}
