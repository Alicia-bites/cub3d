/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:58:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 13:11:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_check(t_mlx *mlx, int txt_type, char *value)
{
	if ((txt_type == NO || txt_type == SO || txt_type == WE
		|| txt_type == EA)
		&& settings_texture_fd_open(mlx, txt_type, value) != 0)
		return (EXIT_FAILURE);
	else if ((txt_type == F || txt_type == C)
		&& settings_rgb(mlx, txt_type, value) != 0)
		return (EXIT_FAILURE);
	else
		return (0);
}
