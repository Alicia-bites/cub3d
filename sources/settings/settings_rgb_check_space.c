/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_rgb_check_space(char *str)
{
	size_t	len;
	size_t	i;
	int	j;

	len = ft_strlen(str);
	if (len == 0)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	i = 0;
	j = (int)len - 1;
	while (str[i] && ft_isspace(str[i] == 1))
		i++;
	if (i == len)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	while (str[j] && ft_isspace(str[j] == 1))
		j--;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && (int)i != j)
			return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
		i++;
	}
	return (0);
}
