/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check_dup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:36:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 12:40:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_rgb_check_dup(t_game *game, int txt_type)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == F && settings->f_r >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else if (txt_type == C && settings->c_r >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else
		return (0);
}
