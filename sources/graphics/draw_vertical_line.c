/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:36:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/20 11:29:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_vertical_line(t_game *game, int x)
{
		int y;
		
		y = game->drawStart;
		while (y < game->drawEnd)
		{
			my_mlx_pixel_put(game->image, x, y, game->color);
			y++;
		}
	return (0);
}
