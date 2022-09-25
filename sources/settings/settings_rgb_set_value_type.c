/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_set_value_type.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:12:22 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 11:13:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_rgb_set_value_type(int *r, int *g, int *b, int *rgb_tab)
{
	*r = rgb_tab[0];
	*g = rgb_tab[1];
	*b = rgb_tab[2];
}
