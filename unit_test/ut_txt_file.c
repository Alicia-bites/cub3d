/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_txt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:38:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 16:52:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static void	ut_txt_file_map_fd(t_mlx *mlx, char **test)
{
	int	i = 0;

	while (test[i])
	{
		printf("TEST: %s\n", test[i]);
		if (parse_map_fd(test[i], mlx) == 0)
			close(mlx->map_fd);
		i++;
		printf("%s\n", SEP_P);
		mlx->map_fd = FD_NOT_INIT;
	}
}

void	ut_txt_file(void *prj_struc)
{
	t_mlx	*mlx;
	char *test[] = {"map_subject.cub", ".cub", "map_subject.cuub",
		"map_subject", "", "map_subject.cub.cub", NULL};

	if (!prj_struc)
		return ;
	mlx = (t_mlx *)prj_struc;
	ut_txt_file_map_fd(mlx, test);
}
