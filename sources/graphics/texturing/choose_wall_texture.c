/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:25:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/26 14:55:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Make color darker for y-sides: R, G and B byte each divided through two with
// a "shift" and an "and"
static void	make_color_darker_for_y_side(t_game *game, int color, int x, int y)
{
	if (game->side == 1)
		color = (color >> 1) & 8355711;
	game->buf[y][x] = color;
	game->re_buf = 1;
}

static void	increase_texture_coordinate_perscreen_pixel(t_game *game)
{
	game->step = 1.0 * TEX_HEIGHT / game->lineHeight;
}

// First line inside the loop :
// We cast the texture coordinate to integer, and mask with (texHeight - 1)
// in case of overflow.
void	get_pixel_color_along_y_axe(t_game *game, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	texPos;
	
	increase_texture_coordinate_perscreen_pixel(game);
	texPos = (game->drawStart - WINDOW_HEIGHT / 2 + game->lineHeight / 2) * game->step;
	y = game->drawStart;
	while (y < game->drawEnd)
	{
		tex_y = (int)texPos & (TEX_HEIGHT - 1);
		texPos += game->step;
		color = game->texture[game->tex_number][TEX_HEIGHT * tex_y + game->tex_x];
		make_color_darker_for_y_side(game, color, x, y);
		y++;
	}
}

static void	find_x_coordinate_in_texture(t_game *game)
{
	extern int	worldMap[24][24];
	
	game->tex_x = (int)(game->wall_x * (double)TEX_WIDTH);
	if (game->side == 0 && game->ray_dirX > 0)
		game->tex_x = TEX_WIDTH - game->tex_x - 1;
	if (game->side == 1 && game->ray_dirY < 0)
		game->tex_x = TEX_WIDTH - game->tex_x - 1;
}

// tex_number --> the value of the current square minus 1. Why minus 1?
// because there is a texture 0, but map tile 0 has no texture since it
// represents an empty space.
// So, to be able to use texture 0 anyway, we substract so that the map
// tile 1 will have the texture 0, the map tile 2 the texture 1, etc...
// vall_x --> the exact value where the wall was hit, to just the integer
// coordonates of the wall. This is required to know wich x-coordinate of the
// texture we must use. We obtain that value by :
// 1) Calculate the exact x and y of the world game.
// 2) Substract off it the integer value of the wall.
// READ THIS ANTHONY !!!
// In mathematics and computer science, the 'floor' function is the function
// that takes as input a real number x, and gives as output the greatest integer
// less than or equal to x.
void	choose_wall_texture(t_game *game, int x)
{
	extern int	worldMap[24][24];
	
	game->tex_number = worldMap[game->mapX][game->mapY] - 1;
	// if (game->side == 0 && game->ray_dirX < 0)
	// 	game->tex_dir = 0;
	// if (game->side == 0 && game->ray_dirX >= 0)
	// 	game->tex_dir = 1;
	// if (game->side == 1 && game->ray_dirY < 0)
	// 	game->tex_dir = 2;
	// if (game->side == 1 && game->ray_dirY >= 0)
	// 	game->tex_dir = 3;
	if (game->side == 0)
		game->wall_x = game->posY + game->perpWallDist * game->ray_dirY;		
	else
		game->wall_x = game->posX + game->perpWallDist * game->ray_dirX;
	game->wall_x -= floor(game->wall_x);
	find_x_coordinate_in_texture(game);
	get_pixel_color_along_y_axe(game, x);
}