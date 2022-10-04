/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:25:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 15:19:24 by amarchan         ###   ########.fr       */
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
	game->step = 1.0 * TEX_HEIGHT / game->line_height;
}

// First line inside the loop :
// We cast the texture coordinate to integer, and mask with (texHeight - 1)
// in case of overflow.
void	get_pixel_color_along_y_axe(t_game *game, int x)
{
	int		y;
	int		color;
	int		tex_y;
	double	tex_pos;

	increase_texture_coordinate_perscreen_pixel(game);
	tex_pos = (game->draw_start - WINDOW_HEIGHT / 2
			+ game->line_height / 2) * game->step;
	y = game->draw_start;
	while (y < game->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += game->step;
		color = game->texture[game->tex_dir][TEX_HEIGHT * tex_y + game->tex_x];
		make_color_darker_for_y_side(game, color, x, y);
		y++;
	}
}

static void	find_x_coordinate_in_texture(t_game *game)
{
	game->tex_x = (int)(game->wall_x * (double)TEX_WIDTH);
	if (game->side == 0 && game->ray_dir_x > 0)
		game->tex_x = TEX_WIDTH - game->tex_x - 1;
	if (game->side == 1 && game->ray_dir_y < 0)
		game->tex_x = TEX_WIDTH - game->tex_x - 1;
}

// 0 --> facing South
// 1 --> facing North
// 2 --> facing West
// 3 --> facing East
void	choose_wall_texture(t_game *game, int x)
{
	if (game->side == 0 && game->ray_dir_x < 0)
		game->tex_dir = 1;
	if (game->side == 0 && game->ray_dir_x >= 0)
		game->tex_dir = 0;
	if (game->side == 1 && game->ray_dir_y < 0)
		game->tex_dir = 2;
	if (game->side == 1 && game->ray_dir_y >= 0)
		game->tex_dir = 3;
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	find_x_coordinate_in_texture(game);
	get_pixel_color_along_y_axe(game, x);
}
