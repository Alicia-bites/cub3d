/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init_line_bzero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:57:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 15:11:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_init_line_bzero(int *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		line[i] = '\0';
		i++;
	}
	line[i] = '\0';
}
