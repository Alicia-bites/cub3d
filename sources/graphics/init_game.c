/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 17:25:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Start mlx loop, set hook on keys and start raycasting loop.
static int	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
	game->img.mlx_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.mlx_img,
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	start_ray_casting_loop(game);
	mlx_key_hook(game->win, &key_hook, game);
	mlx_hook(game->win, 17, 0, ft_redcross, game);
	mlx_loop(game->mlx);
	return (0);
}

int	init_game(t_game *game)
{
	int	err;

	game->mlx = mlx_init();

	init_struct(game);
	err = init_buf(game);
	if (err)
		return (err);
	init_texture(game);
	generate_textures(game);
	start_game(game);
	return (0);
}