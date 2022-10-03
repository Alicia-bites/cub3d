/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:34:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:38:05 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_left(t_game *game)
{	
	if (game->map_tab[(int)(game->pos_x + game->dir_x
			* MOVESPEED)][(int)game->pos_y] <= 0)
		game->pos_x -= game->plane_x * MOVESPEED;
	if (game->map_tab[(int)(game->pos_x)][(int)(game->pos_y + game->dir_y
		* MOVESPEED)] <= 0)
		game->pos_y -= game->plane_y * MOVESPEED;
}
