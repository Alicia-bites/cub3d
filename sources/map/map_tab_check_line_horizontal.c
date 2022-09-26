/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_check_line_horizontal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:35:37 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 11:47:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_check_line_horizontal(int *line, int i, int dir, int width)
{
	if (dir == -1)
	{
		if (i == 0 || line[i - 1] == ' ')
			return (ft_panic(-1, __func__, ERR_MAP_CLOSURE));
	}
	else
	{
		if (i == (width - 1) || line[i + 1] == ' ')
			return (ft_panic(-1, __func__, ERR_MAP_CLOSURE));
	}
	return (0);
}
