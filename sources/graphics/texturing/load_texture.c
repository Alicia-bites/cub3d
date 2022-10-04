/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:38:42 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 16:22:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img)
		return (NO_ADDRESS);
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
	return (0);
}

int	load_texture(t_game *game)
{
	t_img	img;
	int		err;

	err = 0;
	err = load_image(game, game->texture[0], game->settings.so, &img);
	err = load_image(game, game->texture[1], game->settings.no, &img);
	err = load_image(game, game->texture[2], game->settings.we, &img);
	err = load_image(game, game->texture[3], game->settings.ea, &img);
	printf("err = %d\n", err);
	if (err)
		return (err);
	err = load_image(game, game->texture[4], "texture/bluestone.xpm", &img);
	err = load_image(game, game->texture[5], "texture/mossy.xpm", &img);
	err = load_image(game, game->texture[6], "texture/wood.xpm", &img);
	err = load_image(game, game->texture[7], "texture/colorstone.xpm", &img);
	err = load_image(game, game->texture[8], "texture/barrel.xpm", &img);
	err = load_image(game, game->texture[9], "texture/pillar.xpm", &img);
	err = load_image(game, game->texture[10], "texture/greenlight.xpm", &img);
	if (err)
		return (err);
	return (0);
}
