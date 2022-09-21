/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_rm_nl.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:23:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 15:35:52 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_texture_fd_rm_nl(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len > 0)
	len--;
	while (len > 0 && ft_isspace(filename[len]) == 1)
	{
		filename[len] = '\0';
		len--;
	}
}
