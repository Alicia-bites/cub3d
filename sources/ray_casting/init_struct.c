/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 14:14:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// We add 0.5 to the starting position in order to prevent bad display of
// raycasting.
int	init_struct(t_game *game)
{
	game->pos_x = game->settings.map_player_sp_x + 0.5;
	game->pos_y = game->settings.map_player_sp_y + 0.5;
	init_starting_direction(game);
	game->re_buf = 0;
	return (0);
}
