/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/29 11:34:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_mlx(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx, game->img.mlx_img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

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
	free_mlx(game);
	free_texture_tab(game->texture);
}