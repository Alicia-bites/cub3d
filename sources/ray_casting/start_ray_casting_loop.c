/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/26 16:06:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void    clear_window(t_game *game)
// {
// 	ft_bzero(game->image->addr, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
// }

int	start_ray_casting_loop(t_game *game)
{
	int	x;

	x = 0;
	init_re_buf(game);
	// draw_ceiling(game);
	while (x < WINDOW_WIDTH)
	{
		calculate_ray_position_and_direction(game, x);
		game->hit = 0;
		calculate_step(game);
		perform_dda(game);
		draw_wall(game);
		choose_wall_texture(game, x);
		x++;
	}
	draw_floor(game);
	draw_vertical_line(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
	return (0);
}