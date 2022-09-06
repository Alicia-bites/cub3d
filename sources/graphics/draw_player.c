/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:08:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/02 18:08:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_player(t_mlx *mlx)
{
	t_coord	pen;
	t_data	img;
	
	pen.draw_loc_x = 500;
	pen.draw_loc_y = 500;
	img.img = mlx_new_image(mlx->mlx_ptr, 15, 15);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	pen.x = 0;
	while (pen.x < 15)
	{
		pen.y = 0;
		while (pen.y < 15)
		{
			my_mlx_pixel_put(&img, pen.x, pen.y, PLAYER_COLOR);
			pen.y++;
		}
		pen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img,
		pen.draw_loc_x, pen.draw_loc_y);
	mlx->player_x = 500;
	mlx->player_y = 500;
	mlx->player_image = img.img;	
}
