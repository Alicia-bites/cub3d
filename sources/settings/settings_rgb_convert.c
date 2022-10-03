/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:57:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/03 14:09:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* THANK YOU FOR YOUR TIPS JONAS THE 'BG'
 *
 */
void	settings_rgb_convert(t_settings *settings)
{
	settings->floor = settings->f_r << 16 | settings->f_g << 8
		| settings->f_b;
	settings->ceil = settings->c_r << 16 | settings->c_g << 8
		| settings->c_b;
}
