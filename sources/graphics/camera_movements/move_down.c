/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:33:32 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 14:32:25 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_down(t_game *game)
{
	// extern int worldMap[24][24];
	
	if(game->map_tab[(int)(game->posX - game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX -= game->dirX * MOVESPEED;
	if(game->map_tab[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)] == 0)
		game->posY -= game->dirY * MOVESPEED;
}
