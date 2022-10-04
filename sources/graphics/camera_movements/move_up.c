/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:32:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 14:19:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_up(t_game *game)
{
	if (!can_go(game))
		return ;
	// if (game->map_tab[(int)(game->pos_x + game->dir_x
	// 		* MOVESPEED)][(int)game->pos_y] <= 0)
	// 	game->pos_x += game->dir_x * MOVESPEED;
	// if (game->map_tab[(int)(game->pos_x)][(int)(game->pos_y + game->dir_y
	// 	* MOVESPEED)] <= 0)
	// 	game->pos_y += game->dir_y * MOVESPEED;

	if (game->map_tab[(int)game->pos_y][(int)(game->pos_x + game->dir_x * MOVESPEED)] <= 0)
		game->pos_x += game->dir_x * MOVESPEED;
	if (game->map_tab[(int)(game->pos_y + game->dir_y * MOVESPEED)][(int)(game->pos_x)] <= 0)
		game->pos_y += game->dir_y * MOVESPEED;
}
