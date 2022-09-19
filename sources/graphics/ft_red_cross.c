/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:15:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/14 14:03:03 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//close window
int	ft_redcross(t_game *game, int x)
{
	if (x == 0)
		printf("Leaving the game. See you later!\n");
	mlx_loop_end(game->mlx);
	return (0);
}
