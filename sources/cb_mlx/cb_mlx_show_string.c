/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_show_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:53:37 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/07 22:20:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cb_mlx_show_string(char *title, char *s)
{
	if (!s)
		printf("%s | ptr: NULL\tvalue: NULL\n", title);
	else
		printf("%s | ptr: %p\tvalue: %s\n", title, s, s);
}
