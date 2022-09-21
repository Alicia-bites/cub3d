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

void	generate_textures(t_game *game)
{
	int	x;
	int y;
	int xorcolor;
	int	ycolor;
	int	xycolor;
	
	x = 0;

	while (x < TEX_WIDTH)
	{
		y = 0;
		xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
		ycolor = y * 256 / TEX_HEIGHT;
		xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
		while (y < TEX_HEIGHT)
		{
			int xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			int ycolor = y * 256 / TEX_HEIGHT;
			int xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			game->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			game->texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			game->texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			game->texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			game->texture[4][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
			game->texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			game->texture[6][TEX_WIDTH * y + x] = 65536 * ycolor; //red gradient
			game->texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			y++;
		}
		x++;
	}

}

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
	int	err;

	err = init_struct(game);	
	err = init_buf(game);
	init_texture(game);
	if (err)
		return (err);
	generate_textures(game);
	start_game(game);
	return (0);
}