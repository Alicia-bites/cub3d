/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 15:10:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win =  mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	game->image->mlx_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->image->addr = mlx_get_data_addr(game->image->mlx_img, &game->image->bits_per_pixel, &game->image->line_length, &game->image->endian);
	mlx_key_hook(game->win, key_hook, game);
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