/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_go.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:45:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/04 13:56:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Returns 1 if tile exists and 0 if it doesn't
int	can_go(t_game *game)
{
	if (game->map_x < 0 && game->map_x > game->settings.map_width)
		return (0);
	if (game->map_y < 0 && game->map_y > game->settings.map_height)
		return (0);
	return (1);
}
