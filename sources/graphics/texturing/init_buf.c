/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:20:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 14:17:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	fill_buf_with_zero(t_game *game)
{
	int	i;
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
	return (0);
}

static int	malloc_lines_for_buf(t_game *game)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		game->buf[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * WINDOW_WIDTH));
		if (!game->buf[i])
			return (errors_handler(MALLOC_ERROR, __func__));
		i++;
	}
	return (0);
}

int	init_buf(t_game *game)
{
	int	err;

	err = 0;
	game->buf = (int **)malloc(sizeof(int *) * WINDOW_HEIGHT);
	if (!game->buf)
		return (errors_handler(MALLOC_ERROR, __func__));
	err = malloc_lines_for_buf(game);
	if (err)
		return (err);
	fill_buf_with_zero(game);
	return (0);
}
