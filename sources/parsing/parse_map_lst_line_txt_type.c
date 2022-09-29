/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_line_txt_type.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:31:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/29 11:17:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_line_txt_type(char *line)
{
	if (ft_strncmp(line, MAP_TEXT_NO, ft_strlen(MAP_TEXT_NO)) == 0)
		return (NO);
	else if (ft_strncmp(line, MAP_TEXT_SO,
			ft_strlen(MAP_TEXT_SO)) == 0)
		return (SO);
	else if (ft_strncmp(line, MAP_TEXT_WE,
			ft_strlen(MAP_TEXT_WE)) == 0)
		return (WE);
	else if (ft_strncmp(line, MAP_TEXT_EA,
			ft_strlen(MAP_TEXT_EA)) == 0)
		return (EA);
	else if (ft_strncmp(line, MAP_TEXT_F,
			ft_strlen(MAP_TEXT_F)) == 0)
		return (F);
	else if (ft_strncmp(line, MAP_TEXT_C,
			ft_strlen(MAP_TEXT_C)) == 0)
		return (C);
	else
		return (MAP);
}
