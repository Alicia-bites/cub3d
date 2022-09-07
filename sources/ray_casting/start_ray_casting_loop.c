/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/07 11:55:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    clear_window(t_data *img)
{
	ft_bzero(img->addr, SCREEN_HEIGHT * SCREEN_WIDTH * 4);
}

int	start_ray_casting_loop(t_mlx *mlx)
{
	int			x;
	// t_vector	vec;
	t_palette	color;

	// set_vectors(&vec);
	x = 0;
	clear_window(&mlx->img);
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(&mlx->vec, x);
		calculate_step(&mlx->vec);
		perform_dda(&mlx->vec, mlx->map);
		draw_wall(&mlx->vec);
		choose_wall_color(mlx->map, &mlx->vec, &color);
		draw_vertical_line(x, mlx->vec, color.color_wall, &mlx->img);
		x++;
		// printf("x = %d\n", x);
	}
	// mlx->vec = vec;
	// printf("IN START RAY CASTING --> vec.posX = %f\n", vec.posX);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}
