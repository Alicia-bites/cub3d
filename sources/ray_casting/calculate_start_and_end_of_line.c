/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_start_and_end_of_line.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:56:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:54:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Calculate distance projected on camera direction (Euclidean 
// distance would give fisheye effect!)
int	calculate_start_and_end_of_line(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->map_x - game->pos_x
				+ (1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->perp_wall_dist = (game->map_y - game->pos_y
				+ (1 - game->step_y) / 2) / game->ray_dir_y;
	game->line_height = (int)(WINDOW_HEIGHT / game->perp_wall_dist);
	game->draw_start = -(game->line_height) / 2 + WINDOW_HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + WINDOW_HEIGHT / 2;
	if (game->draw_end >= WINDOW_HEIGHT)
		game->draw_end = WINDOW_HEIGHT - 1;
	return (0);
}
