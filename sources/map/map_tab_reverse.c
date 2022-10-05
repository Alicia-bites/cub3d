/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:01:28 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 11:43:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_reverse(t_game *game)
{
	int	**tab;

	tab = map_tab_init(game->settings.map_width, game->settings.map_height);
	if (tab == NULL)
		return (EXIT_FAILURE);
	map_tab_reverse_copy(game->map_tab, tab, game->settings.map_width,
			game->settings.map_height);
	game->map_tab = tab;
	map_tab_reverse_settings(&game->settings, tab);
	return (0);
}
