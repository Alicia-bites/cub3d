/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:34:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 13:34:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_left(t_game *game)
{
	extern int	worldMap[24][24];
	
	if(worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] == 0)
		game->posX -= game->planeX * MOVESPEED;
	if(worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] == 0)
		game->posY -= game->planeY * MOVESPEED;

}
