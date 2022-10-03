/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:36:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 13:56:10 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_vertical_line(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->img.addr = mlx_get_data_addr(game->img.mlx_img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (game->buf[y][x] == 0x0 && y < WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(&game->img, x, y, CEILING_COLOR);
			else if (game->buf[y][x] == 0x0 && y > WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(&game->img, x, y, FLOOR_COLOR);
			else
				my_mlx_pixel_put(&game->img, x, y, game->buf[y][x]);
			x++;
		}
		y++;
	}
}
