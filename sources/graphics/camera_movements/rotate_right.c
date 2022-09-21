/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:35:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 15:10:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_right(t_game *game)
{
	game->oldDirX = game->dirX;
	game->dirX = game->dirX * cos(-ROTSPEED) - game->dirY * sin(-ROTSPEED);
	game->dirY = game->oldDirX * sin(-ROTSPEED) + game->dirY * cos(-ROTSPEED);
	game->oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(-ROTSPEED) - game->planeY * sin(-ROTSPEED);
	game->planeY = game->oldPlaneX * sin(-ROTSPEED) + game->planeY * cos(-ROTSPEED);
}
