/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_show_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:53:37 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 09:28:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_show_string(char *title, char *s)
{
	if (!s)
		printf("%s | ptr: NULL\tvalue: NULL\n", title);
	else
		printf("%s | ptr: %p\tvalue: %s\n", title, s, s);
}
