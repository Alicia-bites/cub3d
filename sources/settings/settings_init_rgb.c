/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_init_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:54:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/03 13:55:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_init_rgb(t_settings *settings)
{
	settings->f_r = -1;
	settings->f_g = -1;
	settings->f_b = -1;
	settings->floor = -1;
	settings->c_r = -1;
	settings->c_g = -1;
	settings->c_b = -1;
	settings->ceil = -1;
}
