/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:08:16 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 12:27:38 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iterator;

	if (lst)
	{
		iterator = lst;
		while (iterator)
		{
			f(iterator->line);
			iterator = iterator->next;
		}
	}
}
