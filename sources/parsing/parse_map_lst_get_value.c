/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_get_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:31:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 13:13:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*parse_map_lst_get_value(t_mlx *mlx, int txt_type, char *str)
{
	t_settings	*settings;

	settings = &mlx->settings;
	if (txt_type == NO && settings->fd_no >= 0)
		return (&str[ft_strlen(MAP_TEXT_NO)]);
	else if (txt_type == SO && settings->fd_so >= 0)
		return (&str[ft_strlen(MAP_TEXT_SO)]);
	else if (txt_type == WE && settings->fd_we >= 0)
		return (&str[ft_strlen(MAP_TEXT_WE)]);
	else if (txt_type == EA && settings->fd_ea >= 0)
		return (&str[ft_strlen(MAP_TEXT_EA)]);
	else if (txt_type == F && settings->f_r >= 0)
		return (&str[ft_strlen(MAP_TEXT_F)]);
	else if (txt_type == C && settings->c_r >= 0)
		return (&str[ft_strlen(MAP_TEXT_C)]);
	else
		return (NULL);
}
