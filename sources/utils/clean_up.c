/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 15:22:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_texture_tab(int **texture)
{
	int	i;

	i = 0;
	while(i < 11)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
}

void	clean_up(t_game *game)
{
	free_texture_tab(game->texture);
}