/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:51:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 16:29:03 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	look_up(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(ROTSPEED) - game->dir_y * sin(ROTSPEED);
	game->dir_y = game->old_dir_x * sin(ROTSPEED) + game->dir_y
		* cos(ROTSPEED);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(ROTSPEED) - game->plane_y
		* sin(ROTSPEED);
	game->plane_y = game->old_plane_x * sin(ROTSPEED) + game->plane_y
		* cos(ROTSPEED);
}
