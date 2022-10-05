/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_reverse_settings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:38:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 11:53:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_reverse_settings(t_settings *settings, int **tab)
{
	int	tmp_height;
	int	i;
	int	j;

	tmp_height = settings->map_height;
	settings->map_height = settings->map_width;
	settings->map_width = tmp_height;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'E'
				|| tab[i][j] == 'S' || tab[i][j] == 'W')
			{
				settings->map_player_sp_x = j;
				settings->map_player_sp_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
