/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/13 11:13:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_game(t_list *map)
{
	t_game		game;
	t_data		info;
	t_vector	vec;
	
	(void)map;
	set_vectors(&vec);
	game.vec = vec;
	game.win_ptr = NULL;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (-2);
	game.win_ptr = mlx_new_window(game.mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3d");
	info.img = mlx_new_image(game.mlx_ptr, SCREEN_WIDTH, SCREEN_WIDTH);
	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel,
		&info.line_length, &info.endian);
	game.info = info;
	// game.map = map;
	// start_ray_casting_loop(&mlx);
	mlx_key_hook(game.win_ptr, ft_key_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_redcross, &game);
	// mlx_key_hook(game.win_ptr, keypress, &game);
	mlx_loop_hook(game.win_ptr, start_ray_casting_loop, &game);
	// For each frame the game requires, it will call the function
	// start_ray_casting_loop with the parameter &game
	mlx_loop(game.mlx_ptr);
	mlx_destroy_image(&game, &game.info);
	mlx_destroy_window(&game, &game.win_ptr);
	mlx_destroy_display(&game);
	free_mlx(&game);
	return (1);
}