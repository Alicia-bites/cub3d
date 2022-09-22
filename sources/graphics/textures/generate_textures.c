/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:35:46 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Double loop that goes through every pixel of the textures, and then the 
// corresponding pixel of each texture gets a certain value calculated out
// of x and y. Some textures get a XOR pattern, some a simple gradient, 
// others a sort of brick pattern.
void	generate_textures(t_game *game)
{
	int	x;
	int y;

	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			game->xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			game->ycolor = y * 256 / TEX_HEIGHT;
			game->xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			game->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			game->texture[1][TEX_WIDTH * y + x] = game->xycolor + 256 * game->xycolor + 65536 * game->xycolor; //sloped greyscale
			game->texture[2][TEX_WIDTH * y + x] = 256 * game->xycolor + 65536 * game->xycolor; //sloped yellow gradient
			game->texture[3][TEX_WIDTH * y + x] = game->xorcolor + 256 * game->xorcolor + 65536 * game->xorcolor; //xor greyscale
			game->texture[4][TEX_WIDTH * y + x] = 256 * game->xorcolor; //xor green
			game->texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			game->texture[6][TEX_WIDTH * y + x] = 65536 * game->ycolor; //red gradient
			game->texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			y++;
		}
		x++;
	}
}