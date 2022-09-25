/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_set_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:47:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 16:48:31 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_rgb_set_value(t_game *game, int txt_type, int *rgb_tab)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == F)
		settings_rgb_set_value_type(&settings->f_r, &settings->f_g,
			&settings->f_b, rgb_tab);
	else if (txt_type == C)
		settings_rgb_set_value_type(&settings->c_r, &settings->c_g,
			&settings->c_b, rgb_tab);
}
