/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:15:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/01 12:15:39 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//close window
int	ft_redcross(t_mlx *mlx, int x)
{
	if (x == 0)
		ft_printf("Leaving the game. See you later!\n");
	if (x == 1)
		ft_printf(
			"WINNER! You collected all the forms and you are " \
			"free from bureaucracie! Until the next time...\n");
	if (x == 2)
		ft_printf(
			"LOOSER! You didn't collect all the forms! " \
			"Your soul belong to us now...\n");
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}
