/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/07 22:27:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_list	*map;
	t_mlx	mlx;
	
	cb_mlx_init(&mlx);
	cb_mlx_show(&mlx);
	map = NULL;
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Oups, wrong number of arguments!", 2);
		return (-1);
	}
	map = ft_parse(argv[1]);
	init_game(map);
	return (0);
}
