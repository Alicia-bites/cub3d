/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_re_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:55:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:04:02 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_re_buf(t_game *game)
{
	int	i;
	int	j;

	if (game->re_buf == 1)
	{
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
		game->re_buf = 0;
	}
}
