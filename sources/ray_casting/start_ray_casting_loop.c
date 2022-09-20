/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/20 11:29:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void    clear_window(t_game *game)
{
	ft_bzero(game->image->addr, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
}

int	start_ray_casting_loop(t_game *game)
{
	int	x;
	clear_window(game);
	for(x = 0; x < WINDOW_WIDTH; x++)
	{
		calculate_ray_position_and_direction(game, x);
		calculate_step(game);
		perform_dda(game);
		draw_wall(game);
		choose_wall_color(game);
		draw_vertical_line(game, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image->mlx_img, 0, 0);
	return (0);
}
