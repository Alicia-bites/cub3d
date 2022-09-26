/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/26 13:13:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static t_img	*init_image(t_img *image)
// {
// 	image = ft_calloc(1, sizeof(t_img));
// 	if (!image)
// 		return (NULL);
// 	return (image);
// }

int	init_struct(t_game *game)
{
	game->posX = 22.0;
	game->posY = 11.5;
	game->dirX = -1.0;
	game->dirY = 0.0;
	game->planeX = 0.0;
	game->planeY = 0.66;
	game->re_buf = 0;
	return (0);
	return (0);
}
