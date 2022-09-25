/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 17:36:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_free(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map_tab)
		return ;
	while (game->map_tab[i])
	{
		if (game->map_tab[i])
		{
			free(game->map_tab[i]);
			game->map_tab[i] = NULL;
		}
		i++;
	}
	free(game->map_tab);
	game->map_tab = NULL;
}
