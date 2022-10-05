/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_starting_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:18:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 15:56:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	face_north(t_game *game)
{
	game->dir_x = -1.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0 * game->dir_y;
	game->plane_y = -0.66 * game->dir_x;
}

static void	face_south(t_game *game)
{
	game->dir_x = 1.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0 * game->dir_y;
	game->plane_y = 0.66 * -game->dir_x;
}

static void	face_east(t_game *game)
{
	game->dir_x = 0.0;
	game->dir_y = 1.0;
	game->plane_x = 0.66 * game->dir_y;
	game->plane_y = 0.0 * game->dir_x;
}

static void	face_west(t_game *game)
{
	game->dir_x = 0.0;
	game->dir_y = -1.0;
	game->plane_x = 0.66 * game->dir_y;
	game->plane_y = 0.0 * game->dir_x;
}

// Check if player is facing North, South, East or West
void	init_starting_direction(t_game *game)
{
	if (game->settings.map_player_sp_val == 'N')
		face_north(game);
	else if (game->settings.map_player_sp_val == 'S')
		face_south(game);
	else if (game->settings.map_player_sp_val == 'E')
		face_east(game);
	else if (game->settings.map_player_sp_val == 'W')
		face_west(game);
}
