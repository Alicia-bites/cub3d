/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:15:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/29 17:35:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//close window
int	ft_redcross(t_game *game, int x)
{
	int ret;
	
	if (x == 0)
		printf("Leaving the game. See you later!\n");
	ret = mlx_loop_end(game->mlx);
	printf("ret = %d\n", ret);
	return (0);
}
