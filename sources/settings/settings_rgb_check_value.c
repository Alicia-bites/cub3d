/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:53:08 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 11:24:26 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* @BRIEF:
 * check value between 0 and 255
 *
 * @PARAM:
 * char *: string of one of the rgb value
 * int *: address of r/g/b tab index to store int value
 *
 * @RETURN:
 * = 0: ok
 * != 0: error
 *
 * @VALID USE CASE:
 * 000255
 * +255
 * +0255
 *
 * @INVALID USE CASE:
 * -1
 *  256
 *  ++255
 *  00+255
 */
int	settings_rgb_check_value(char *str, int *tab_i)
{
	unsigned long long	value;
	int					i;

	i = 0;
	while (str[i] && (ft_isspace(str[i]) == 1 || ft_ispolarity(str[i]) == 1
			|| str[i] == '0'))
		i++;
	if (ft_strlen(&str[i]) > 3)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	value = ft_atoll((const char *)str);
	if (value > 255)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	*tab_i = (int)value;
	return (0);
}
