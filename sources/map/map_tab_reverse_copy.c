/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_reverse_copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:21:31 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 12:21:32 by abarrier         ###   ########.fr       */
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
//			tab_dest[line][col] = tab_src[col][line];
			tab_dest[col][line] = tab_src[line][col];
			line++;
		}
//		printf("DEBUG: line:%d\tcol:%d\b", line, col);
//		tab_dest[line][col] = '\0';
		tab_dest[col][line] = '\0';
		col++;
	}
}
