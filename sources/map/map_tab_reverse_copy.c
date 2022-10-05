/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_reverse_copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:21:31 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 13:35:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_reverse_copy(int **tab_src, int **tab_dest,
		int height, int width)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (col < width)
	{
		line = 0;
		while (line < height)
		{
			tab_dest[line][col] = tab_src[col][line];
			line++;
		}
		col++;
	}
}
