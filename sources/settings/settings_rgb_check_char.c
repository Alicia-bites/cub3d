/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:53:08 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 16:56:31 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_rgb_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0 &&
			str[i] != MAP_COLOR_SEP)
			return (ft_panic(-1, __func__, ERR_MAP_COLOR_CHAR));
		i++;
	}
	return (0);
}
