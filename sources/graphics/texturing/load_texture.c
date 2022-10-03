/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:38:42 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:49:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

int	load_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->texture[0], game->settings.so, &img);
	load_image(game, game->texture[1], game->settings.no, &img);
	load_image(game, game->texture[2], game->settings.we, &img);
	load_image(game, game->texture[3], game->settings.ea, &img);
	load_image(game, game->texture[4], "texture/bluestone.xpm", &img);
	load_image(game, game->texture[5], "texture/mossy.xpm", &img);
	load_image(game, game->texture[6], "texture/wood.xpm", &img);
	load_image(game, game->texture[7], "texture/colorstone.xpm", &img);
	load_image(game, game->texture[8], "texture/barrel.xpm", &img);
	load_image(game, game->texture[9], "texture/pillar.xpm", &img);
	load_image(game, game->texture[10], "texture/greenlight.xpm", &img);
	return (0);
}
