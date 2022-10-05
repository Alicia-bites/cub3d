/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:33:32 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 14:16:10 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_down(t_game *game)
{
	double	check_x;
	double	check_y;
	double	x;
	double	y;

	y = (game->pos_y + game->dir_y * MOVESPEED);
	x = (game->pos_x + game->dir_x * MOVESPEED);
	check_x = x + game->dir_x * 0.2;
	check_y = y + game->dir_y * 0.2;
	if (game->map_tab[(int)game->pos_y][(int)(game->pos_x
		- game->dir_x * MOVESPEED)] <= 0
		&& game->map_tab[(int)check_y][(int)check_x] != 1
		&& game->map_tab[(int)check_y][(int)check_x] != -1)
		game->pos_x -= game->dir_x * MOVESPEED;
	if (game->map_tab[(int)(game->pos_y - game->dir_y
			* MOVESPEED)][(int)(game->pos_x)] <= 0
		&& game->map_tab[(int)check_y][(int)check_x] != 1
		&& game->map_tab[(int)check_y][(int)check_x] != -1)
		game->pos_y -= game->dir_y * MOVESPEED;
}
