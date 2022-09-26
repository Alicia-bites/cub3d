/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:49:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 09:46:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_init(t_game *game)
{
	t_settings	*settings;

	settings = &game->settings;
	game->map_tab = (int **)malloc(sizeof(int *)
			* (settings->map_height + 1));
	if (game->map_tab == NULL)
		return (ft_panic(-1, __func__, ERR_MALLOC));
	map_tab_init_bzero(game->map_tab, settings->map_height);
	if (map_tab_init_line(game->map_tab, settings->map_height,
			settings->map_width) == NULL)
	{
		map_tab_free(game);
		return (EXIT_FAILURE);
	}
	return (0);
}
