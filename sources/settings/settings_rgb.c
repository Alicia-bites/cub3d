/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:18:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 10:50:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* @BRIEF:
 * split rgb value into char ** variable and check rgb content as:
 * > map color separator number
 * > forbidden char
 * > no space between digit
 * > value between 0 and 255
 *
 * @NOTE:
 * full rgb value must not contain the type as 'F' or 'O' (if F 255,0,0 then
 * rgb = 255,0,0)

 * @PARAM:
 * t_game *: typedef structure game
 * int: texture type
 * char *: full rgb value without type object
 *
 * @RETURN:
 * = 0: ok
 * != 0: error
 *
 * @INVALID USE CASE: wrong map color separator number
 * 255,0,0,0
 * @INVALID USE CASE: forbidden char
 * abc,0,0
 * @INVALID USE CASE: space between digit
 * 255 0,0,0
 * @INVALID USE CASE: value over range
 * 500,0,0
 */
int	settings_rgb(t_game *game, int txt_type, char *rgb)
{
	char	**rgb_lst;
	int		rgb_tab[3];

	rgb_lst = NULL;
	rgb_tab[0] = 0;
	rgb_tab[1] = 0;
	rgb_tab[2] = 0;
	if (ft_strnchar(rgb, MAP_COLOR_SEP) != 2)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_DEF));
	rgb_lst = ft_split((const char *)rgb, MAP_COLOR_SEP);
	if (!rgb_lst)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	settings_rgb_rm_space_end(rgb_lst);
	if (settings_rgb_check(rgb_lst, rgb_tab) != 0)
	{
		ft_free_ptrptr_str(rgb_lst);
		return (EXIT_FAILURE);
	}
	settings_rgb_set_value(game, txt_type, rgb_tab);
	ft_free_ptrptr_str(rgb_lst);
	return (0);
}
