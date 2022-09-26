/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:04:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 18:08:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_show(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != ' ')
				ft_putchar_fd(tab[i][j], 1);
			else
				ft_putchar_fd('-', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
