/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_starting_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:18:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:19:03 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	face_north(t_game *game)
{
	game->dirX = -1.0;
	game->dirY = 0.0;
	game->planeX = 0.0 * game->dirY;
	game->planeY = -0.66 * game->dirX;
}

static void	face_south(t_game *game)
{
	game->dirX = 1.0;
	game->dirY = 0.0;
	game->planeX = 0.0 * game->dirY;
	game->planeY = 0.66 * -game->dirX;
}

static void	face_east(t_game *game)
{
	game->dirX = 0.0;
	game->dirY = 1.0;
	game->planeX = 0.66 * game->dirY;
	game->planeY = 0.0 * game->dirX;
}

static void	face_west(t_game *game)
{
	game->dirX = 0.0;
	game->dirY = -1.0;
	game->planeX = 0.66 * game->dirY;
	game->planeY = 0.0 * game->dirX;
}

// Check if player is facing North, South, East or West
void	init_starting_direction(t_game *game)
{
	if (setup.map_player_sp_val == 'N')
		face_north(game);
	else if (setup.map_player_sp_val == 'S')
		face_south(game);
	else if (setup.map_player_sp_val == 'E')
		face_east(game);
	else if (setup.map_player_sp_val == 'W')
		face_west(game);
}
