/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 12:23:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Check if player is facing North, South, East or West
void	init_starting_direction(t_game *game)
{
	if (setup.map_player_sp_val == 'N')
	{
		game->dirX = -1.0;
		game->dirY = 0.0;
		game->planeX = 0.0 * game->dirY;
		game->planeY = -0.66 * game->dirX;

	}
	else if (setup.map_player_sp_val == 'S')
	{
		game->dirX = 1.0;
		game->dirY = 0.0;
		game->planeX = 0.0 * game->dirY;
		game->planeY = 0.66 * -game->dirX;
	}
	else if (setup.map_player_sp_val == 'E')
	{
		game->dirX = 0.0;
		game->dirY = 1.0;
		game->planeX = 0.66 * game->dirY;
		game->planeY = 0.0 * game->dirX;
	}
	else if (setup.map_player_sp_val == 'W')
	{
		game->dirX = 0.0;
		game->dirY = -1.0;
		game->planeX = 0.66 * game->dirY;
		game->planeY = 0.0 * game->dirX;
	}
}

int	init_struct(t_game *game)
{
	game->posX = setup.map_player_sp_y;
	game->posY = setup.map_player_sp_x;
	init_starting_direction(game);
	game->re_buf = 0;
	return (0);
}
