/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 13:21:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_img	*init_image(t_img *image)
{
	image = ft_calloc(1, sizeof(t_img));
	if (!image)
		return (NULL);
	return (image);
}

int	init_struct(t_game *game)
{
	game->image = init_image(game->image);
	game->posX = 22;
	game->posY = 12;
	game->dirX = -1;
	game->dirY = 0;
	game->planeX = 0.0;
	game->planeY = 0.66;
	game->dirX = -1;
	game->dirY = 0;
	game->width = WINDOW_WIDTH;
	game->height = WINDOW_HEIGHT;
	return (0);
}
