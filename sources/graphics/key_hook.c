/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:18:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/07 10:23:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == K_W)
		move_up(game);
	if (keycode == K_S)
		move_down(game);
	if (keycode == K_A)
		move_left(game);
	if (keycode == K_D)
		move_right(game);
	if (keycode == K_RIGHT)
		rotate_right(game);
	if (keycode == K_LEFT)
		rotate_left(game);
	if (keycode == ESC)
		ft_redcross(game, 0);
	start_ray_casting_loop(game);
	return (0);
}
