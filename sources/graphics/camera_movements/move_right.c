/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:34:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 16:50:45 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_right(t_game *game)
{
	double	check_x;
	double	check_y;
	
	game->map_y = (game->pos_y + game->dir_y * MOVESPEED);
	game->map_x = (game->pos_x + game->dir_x * MOVESPEED);
	check_x = game->map_x + game->dir_x * 0.2;
	check_y = game->map_y + game->dir_y * 0.2;
	// if (game->map_tab[(int)game->pos_y][(int)(game->pos_x - game->dir_x
	// 	* MOVESPEED)] <= 0
	// 	&& game->map_tab[(int)check_y][(int)check_x] != -1)
	// 	game->pos_x += game->plane_x * MOVESPEED;
	// if (game->map_tab[(int)(game->pos_y - game->dir_y
	// 	* MOVESPEED)][(int)(game->pos_x)] <= 0
	// 	&& game->map_tab[(int)check_y][(int)check_x] != -1)
	// 	game->pos_y += game->plane_y * MOVESPEED;

	// if (game->map_tab[(int)(game->pos_x - game->dir_x
	// 		* MOVESPEED)][(int)game->pos_y] <= 0 && game->map_tab[(int)check_x][(int)check_y] != -1)
	// 	game->pos_x += game->plane_x * MOVESPEED;
	// if (game->map_tab[(int)(game->pos_x)][(int)(game->pos_y - game->dir_y
	// 	* MOVESPEED)] <= 0 && game->map_tab[(int)check_x][(int)check_y] != -1)
	// 	game->pos_y += game->plane_y * MOVESPEED;

	if (game->map_tab[(int)(game->pos_x - game->dir_x
			* MOVESPEED)][(int)game->pos_y] != 1)
		game->pos_x += game->plane_x * MOVESPEED;
	if (game->map_tab[(int)(game->pos_x)][(int)(game->pos_y - game->dir_y
		* MOVESPEED)] != 1)
		game->pos_y += game->plane_y * MOVESPEED;
}
