/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:50:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 15:18:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fill_textures_tab_with_zero(t_game *game)
{
	int	i;
	int	j;

	i = 0;
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
}

static int	malloc_lines_for_textures_tab(t_game *game)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		game->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH));
		if (!game->texture[i])
			return (errors_handler(MALLOC_ERROR, __func__));
		i++;
	}
	return (0);
}

int	init_texture(t_game *game)
{
	int	err;
	
	err = 0;
	game->texture = (int **)malloc(sizeof(int *) * 11);
	if (!game->texture)
		return (errors_handler(MALLOC_ERROR, __func__));
	err = malloc_lines_for_textures_tab(game);
	if (err)
		return (err);
	fill_textures_tab_with_zero(game);
	return (0);
}