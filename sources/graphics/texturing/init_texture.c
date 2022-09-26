/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:50:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/26 12:06:25 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_texture(t_game *game)
{
	int	i;
	int	j;
	
	game->texture = (int **)malloc(sizeof(int *) * 11);
	if (!game->texture)
		return (MALLOC_ERROR);
	i = 0;
	while (i < 11)
	{
		game->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH));
		if (!game->texture[i])
			return (MALLOC_ERROR);
		i++;
	}
	while (i < 11)
	{
		j = 0;
		while (j < TEX_WIDTH * TEX_HEIGHT)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}