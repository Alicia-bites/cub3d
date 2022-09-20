/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:38:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 13:50:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

void	ut_rgb(void *prj_struc)
{
	t_mlx	*mlx;
	t_settings	*settings;
	char *test[] = {"255,0,0", "255,1,2", "+255,1,2", "    255, 1 ,0    ",
	       "1 2,0,0", "1+,0,0", ",,", "1,,", "1,2,", " ,  ,   ", 
	       "+,+,+", NULL};
	int	i = 0;

	if (!prj_struc)
		return ;
	mlx = (t_mlx *)prj_struc;
	settings = &mlx->settings;
	while (test[i])
	{
		printf("TEST: %s\n", test[i]);
		settings_rgb(mlx, F, test[i]);
		cb_mlx_show(mlx);
		i++;
		printf("%s\n", SEP_P);
		settings->f_r = 0;
		settings->f_g = 0;
		settings->f_b = 0;
		settings->c_r = 0;
		settings->c_g = 0;
		settings->c_b = 0;
	}
}
