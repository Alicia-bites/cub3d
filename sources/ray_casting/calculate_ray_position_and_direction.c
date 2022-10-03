/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_position_and_direction.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:10:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:40:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_which_box_of_the_map_we_re_in(t_game *game)
{
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
}

static void	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(t_game *game)
{
	game->delta_dist_x = fabs(1 / game->ray_dir_x);
	game->delta_dist_y = fabs(1 / game->ray_dir_y);
}

int	calculate_ray_position_and_direction(t_game *game, int x)
{
	game->camera_x = 2.0 * x / (double)WINDOW_WIDTH - 1.0;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	get_which_box_of_the_map_we_re_in(game);
	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(game);
	return (0);
}
