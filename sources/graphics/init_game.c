/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 15:26:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	init_game(t_list *map)
// {
// 	t_game		game;
// 	t_data		info;
// 	t_vector	vec;
	
// 	(void)map;
// 	set_vectors(&vec);
// 	game.vec = vec;
// 	game.win_ptr = NULL;
// 	game.mlx_ptr = mlx_init();
// 	if (!game.mlx_ptr)
// 		return (-2);
// 	game.win_ptr = mlx_new_window(game.mlx_ptr, SCREEN_WIDTH,
// 			SCREEN_HEIGHT, "Cub3d");
// 	info.img = mlx_new_image(game.mlx_ptr, SCREEN_WIDTH, SCREEN_WIDTH);
// 	info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel,
// 		&info.line_length, &info.endian);
// 	game.info = info;
// 	// game.map = map;
// 	start_ray_casting_loop(&game);
// 	mlx_key_hook(game.win_ptr, ft_key_hook, &game);
// 	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, ft_redcross, &game);
// 	// mlx_key_hook(game.win_ptr, keypress, &game);
// 	mlx_loop_hook(game.win_ptr, start_ray_casting_loop, &game);
// 	// For each frame the game requires, it will call the function
// 	// start_ray_casting_loop with the parameter &game
// 	mlx_loop(game.mlx_ptr);
// 	mlx_destroy_image(&game, &game.info);
// 	mlx_destroy_window(&game, &game.win_ptr);
// 	mlx_destroy_display(&game);
// 	free_mlx(&game);
// 	return (1);
// }

static int	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win =  mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	game->image->mlx_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->image->addr = mlx_get_data_addr(game->image->mlx_img, &game->image->bits_per_pixel, &game->image->line_length, &game->image->endian);
	mlx_key_hook(game->win, keypress, game);
	mlx_loop_hook(game->mlx, start_ray_casting_loop, game);
	mlx_loop(game->mlx);
	mlx_destroy_image(game->mlx, game->image->mlx_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);

	return (0);
}

int	init_game(t_game *game)
{
	init_struct(game);
	start_game(game);
	return (0);
}