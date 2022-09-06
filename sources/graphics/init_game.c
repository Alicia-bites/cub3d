/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 17:08:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_game(t_list *map)
{
	t_mlx	mlx;
	t_data	img;
	
	mlx.win_ptr = NULL;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (-2);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "MAZE");
	img.img = mlx_new_image(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	mlx.img = img;
	mlx.map = map;
	start_ray_casting_loop(&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, ft_redcross, &mlx);
	mlx_key_hook(mlx.win_ptr, ft_key_hook, &mlx);
	mlx_loop_hook(mlx.win_ptr, start_ray_casting_loop, &mlx);
	// For each frame the game requires, it will call the function
	// start_ray_casting_loop with the parameter &mlx
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(&mlx, &mlx.img);
	mlx_destroy_window(&mlx, &mlx.win_ptr);
	mlx_destroy_display(&mlx);
	free_mlx(&mlx);
	return (1);
}