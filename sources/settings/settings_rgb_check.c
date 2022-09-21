/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:58 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 16:48:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* @BRIEF:
 * check rgb content as:
 * > length of the value
 * > forbidden char
 * > no space between digit
 * > value between 0 and 255
 *
 * @PARAM:
 * char **: rgb list of string
 * int *: rgb tab to store int value
 *
 * @RETURN:
 * = 0: ok
 * != 0: error
 *
 * @VALID USE CASE:
 * >255,0,0<
 * >  255,0,0<
 * >   255    ,0,0<
 * >+255,0,0<
 *
 * @INVALID USE CASE: empty value in rgb value
 * ,,
 * 1,,
 * 1,2,
 * @INVALID USE CASE: length of value == 0
 * 255,,0
 * @INVALID USE CASE: forbidden char
 * abc,0,0
 * @INVALID USE CASE: space between digit
 * 255 0,0,0
 * @INVALID USE CASE: value over range
 * 500,0,0
 */
int	settings_rgb_check(char **rgb_lst, int *rgb_tab)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (rgb_lst[len])
		len++;
	if (len != 3)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_DEF));
	while (rgb_lst[i])
	{
		if (ft_strlen(rgb_lst[i]) == 0)
			return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
		if (settings_rgb_check_char(rgb_lst[i]) != 0)
			return (EXIT_FAILURE);
		else if (settings_rgb_check_space(rgb_lst[i]) != 0)
			return (EXIT_FAILURE);
		else if (settings_rgb_check_value(rgb_lst[i], &rgb_tab[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}
