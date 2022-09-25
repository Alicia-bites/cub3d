/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:19:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 16:57:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_ulist	**map_fd_lst;
	
	(void)argc;
	(void)argv;
	cb_mlx_init(&mlx);
	map_fd_lst = ft_lst_init();
	if (!map_fd_lst )
		return (EXIT_FAILURE);
	mlx.map_fd_lst = map_fd_lst;
	ut_rgb(&mlx);
	ut_txt_file(&mlx);
	return (0);
}
