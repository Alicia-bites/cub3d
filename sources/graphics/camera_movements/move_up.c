/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:32:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/29 12:17:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_up(t_game *game)
{
	if(game->map_tab[(int)(game->posX + game->dirX * MOVESPEED)][(int)game->posY] <= 0)
		game->posX += game->dirX * MOVESPEED;
	if(game->map_tab[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)] <= 0)
		game->posY += game->dirY * MOVESPEED;
}
