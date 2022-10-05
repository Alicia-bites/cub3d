/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_line_txt_type.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:31:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 14:58:25 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_line_txt_type(char *line)
{
	if (ft_strncmp(line, MAP_TEXT_NO, 2) == 0
		&& ft_isspace(line[2]) == 1)
		return (NO);
	else if (ft_strncmp(line, MAP_TEXT_SO, 2) == 0
		&& ft_isspace(line[2]) == 1)
		return (SO);
	else if (ft_strncmp(line, MAP_TEXT_WE, 2) == 0
		&& ft_isspace(line[2]) == 1)
		return (WE);
	else if (ft_strncmp(line, MAP_TEXT_EA, 2) == 0
		&& ft_isspace(line[2]) == 1)
		return (EA);
	else if (ft_strncmp(line, MAP_TEXT_F, 1) == 0
		&& ft_isspace(line[1]) == 1)
		return (F);
	else if (ft_strncmp(line, MAP_TEXT_C, 1) == 0
		&& ft_isspace(line[1]) == 1)
		return (C);
	else
		return (MAP);
}
