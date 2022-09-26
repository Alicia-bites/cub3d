/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_line_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 13:54:44 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check_line_char(int c)
{
	if (ft_strchr(MAP_CHARSET, c) == NULL)
		return (ft_panic(-1, __func__, ERR_MAP_CHAR));
	else
		return (0);
}
