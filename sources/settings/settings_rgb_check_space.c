/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:02:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 10:51:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* @BRIEF:
 * check no space between digit
 *
 * @PARAM:
 * char *: string of one of the rgb value
 *
 * @RETURN:
 * = 0: ok
 * != 0: error
 *
 * @VALID USE CASE:
 * >            255<
 * >255            <
 * >     255       <
 *
 * @INVALID USE CASE:
 * >255 0<
 * >   255      1<
 */

static int	settings_rgb_check_space_end(char *str, int *j)
{
	while (str[*j] && ft_isspace(str[*j]) == 1)
		*j -= 1;
	if (*j >= 0 && ft_isdigit(str[*j]) == 0)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	else
		return (0);
}

static int	settings_rgb_check_space_start(char *str, size_t *i, size_t len)
{
	while (str[*i] && (ft_isspace(str[*i]) == 1 || str[*i] == '+'))
		*i += 1;
	if (*i == len)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	else
		return (0);
}

int	settings_rgb_check_space(char *str)
{
	size_t	len;
	size_t	i;
	int		j;

	len = ft_strlen(str);
	if (len == 0)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
	i = 0;
	j = (int)len - 1;
	if (settings_rgb_check_space_start(str, &i, len) != 0)
		return (EXIT_FAILURE);
	if (settings_rgb_check_space_end(str, &j) != 0)
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && (int)i != j)
			return (ft_panic(-1, __func__, ERR_MAP_COLOR_VAL));
		if ((int)i == j)
			break ;
		i++;
	}
	return (0);
}
