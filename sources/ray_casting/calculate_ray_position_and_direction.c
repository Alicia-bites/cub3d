/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_position_and_direction.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:10:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 12:02:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_which_box_of_the_map_we_re_in(t_game *game)
{
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
}

static void	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(t_game *game)
{
	game->deltaDistX = fabs(1 / game->ray_dirX);
	game->deltaDistY = fabs(1 / game->ray_dirY);
}

int	calculate_ray_position_and_direction(t_game *game, int x)
{
	game->cameraX = 2.0 * x / (double)WINDOW_WIDTH - 1.0;
	game->ray_dirX = game->dirX + game->planeX * game->cameraX;
	game->ray_dirY = game->dirY + game->planeY * game->cameraX;
	get_which_box_of_the_map_we_re_in(game);
	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(game);
	return (0);
}
