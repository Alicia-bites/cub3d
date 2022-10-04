/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:34:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 14:17:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_right(t_game *game)
{
	if (!can_go(game))
		return ;
	if (game->map_tab[(int)game->pos_y][(int)(game->pos_x - game->dir_x * MOVESPEED)] <= 0)
		game->pos_x += game->plane_x * MOVESPEED;
	if (game->map_tab[(int)(game->pos_y - game->dir_y * MOVESPEED)][(int)(game->pos_x)] <= 0)
		game->pos_y += game->plane_y * MOVESPEED;
}
