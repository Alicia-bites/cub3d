/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/13 11:19:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    clear_window(t_data *info)
{
	ft_bzero(info->addr, SCREEN_HEIGHT * SCREEN_WIDTH * 4);
}

int	start_ray_casting_loop(t_game *game)
{
	int			x;
	// t_vector	vec;
	t_palette	color;

	// set_vectors(&vec);
	x = 0;
	clear_window(&game->info);
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(&game->vec, x);
		calculate_step(&game->vec);
		perform_dda(&game->vec, game->map);
		draw_wall(&game->vec);
		choose_wall_color(game->map, &game->vec, &color);
		draw_vertical_line(x, game->vec, color.color_wall, &game->info);
		x++;
		// printf("x = %d\n", x);
	}
	// game->vec = vec;
	// printf("IN START RAY CASTING --> vec.posX = %f\n", vec.posX);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->info.img, 0, 0);
	return (0);
}
