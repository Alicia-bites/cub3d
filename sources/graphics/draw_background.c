/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:08:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 12:22:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_background(t_mlx *mlx)
{
	t_coord	pen;
	t_data	img;
	
	pen.draw_loc_x = 0;
	pen.draw_loc_y = 0;
	img.img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	pen.x = 0;
	while (pen.x < SCREEN_WIDTH)
	{
		pen.y = 0;
		while (pen.y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(&img, pen.x, pen.y, BACKGROUND_COLOR);
			pen.y++;
		}
		pen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img,
		pen.draw_loc_x, pen.draw_loc_y);
}