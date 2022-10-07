/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/07 11:09:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_mlx(t_game *game, int err)
{
	if (!game)
		return ;
	if (err)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return ;
	}
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
	if (!texture)
		return ;
	if (texture[i] == NULL)
	{
		free(texture);
		return ;
	}
	while (i < 4)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
}

static void	free_buf(int **buf)
{
	int	i;

	i = 0;
	if (!buf)
		return ;
	if (buf[0] == NULL)
	{
		free(buf);
		return ;
	}
	while (i < WINDOW_HEIGHT)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

void	clean_up(t_game *game, int err)
{
	free_mlx(game, err);
	free_texture_tab(game->texture);
	free_buf(game->buf);
}
