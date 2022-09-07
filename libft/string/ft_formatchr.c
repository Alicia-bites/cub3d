/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:46:04 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/07 18:47:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_formatchr(char *str, char *to_find)
{
	size_t	len_str;
	size_t	len_tofind;

	if (!str || !to_find)
		return (0);
	len_str = ft_strlen(str);
	len_tofind = ft_strlen(to_find);
	if (len_str == 0 || len_tofind == 0)
		return (0);
	len_str--;
	len_tofind--;
	while ((int)len_tofind >= 0)
	{
		if (str[len_str] != to_find[len_tofind])
			return (0);
		len_str--;
		len_tofind--;
	}
	return (&str[len_str]);
}
