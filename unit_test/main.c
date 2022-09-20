/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:19:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 15:20:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_ulist	**map_fd_lst;
	
	cb_mlx_init(&mlx);
	//cb_mlx_show(&mlx);
	map_fd_lst = ft_lst_init();
	if (!map_fd_lst )
		return (EXIT_FAILURE);
	mlx.map_fd_lst = map_fd_lst;
	if (parse(argc, argv, &mlx))
		return (EXIT_FAILURE);
	ft_lst_func_lst(mlx.map_fd_lst, &parse_map_fd_show);
	ut_rgb(&mlx);
	return (0);
}
