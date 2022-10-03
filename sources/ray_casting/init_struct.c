/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 15:49:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_struct(t_game *game)
{
	game->pos_x = game->settings.map_player_sp_y;
	game->pos_y = game->settings.map_player_sp_x;
	init_starting_direction(game);
	game->re_buf = 0;
	return (0);
}
