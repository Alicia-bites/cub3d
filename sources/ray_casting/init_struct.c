/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/03 14:19:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_struct(t_game *game)
{
	game->posX = setup.map_player_sp_y;
	game->posY = setup.map_player_sp_x;
	init_starting_direction(game);
	game->re_buf = 0;
	return (0);
}
