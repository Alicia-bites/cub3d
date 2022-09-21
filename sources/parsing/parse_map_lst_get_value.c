/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_get_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:31:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 14:52:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*parse_map_lst_get_value(t_mlx *mlx, int txt_type, char *str)
{
	t_settings	*settings;

	settings = &mlx->settings;
	if (txt_type == NO)
		return (&str[ft_strlen(MAP_TEXT_NO)]);
	else if (txt_type == SO)
		return (&str[ft_strlen(MAP_TEXT_SO)]);
	else if (txt_type == WE)
		return (&str[ft_strlen(MAP_TEXT_WE)]);
	else if (txt_type == EA)
		return (&str[ft_strlen(MAP_TEXT_EA)]);
	else if (txt_type == F)
		return (&str[ft_strlen(MAP_TEXT_F)]);
	else if (txt_type == C)
		return (&str[ft_strlen(MAP_TEXT_C)]);
	else
		return (NULL);
}
