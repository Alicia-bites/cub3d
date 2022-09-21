/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:20:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/21 17:32:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fill_buf_with_zeros(t_game *game)
{
	int i;
	int	j;
	
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	init_buf(t_game *game)
{
	int	i;
	
	game->buf = (int **)malloc(sizeof(int *) * WINDOW_HEIGHT);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		game->buf[i] = (int *)malloc(sizeof(int) * WINDOW_WIDTH);
		if (!game->buf[i])
			return (MALLOC_ERROR);
		i++;
	}
	fill_buf_with_zeros(game);
	return (0);
}
