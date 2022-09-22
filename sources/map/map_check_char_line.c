/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_char_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 18:07:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check_char_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(MAP_CHARSET, str[i]) == NULL)
			return (ft_panic(-1, __func__, ERR_MAP_CHAR));
		i++;
	}
	return (0);
}
