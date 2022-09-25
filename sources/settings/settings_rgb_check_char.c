/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:53:08 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 16:49:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* @BRIEF:
 * check forbidden char and total of '+' polarity character
 *
 * @PARAM:
 * char *: string of one of the rgb value
 *
 * @RETURN:
 * = 0: ok
 * != 0: error
 *
 * @VALID CASE:
 * >255<
 * >   255<
 * >+255<
 *
 * @INVALID USE CASE:
 * abc
 * 12c
 * %'s
 * >++255<
 */
int	settings_rgb_check_char(char *str)
{
	int		i;
	size_t	n_polarity;

	i = 0;
	n_polarity = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0
				&& str[i] != '+') || (str[i] == '+' && n_polarity > 0))
			return (ft_panic(-1, __func__, ERR_MAP_COLOR_CHAR));
		if (str[i] == '+')
			n_polarity++;
		i++;
	}
	return (0);
}
