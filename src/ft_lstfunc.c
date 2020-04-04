/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "ft_list.struct.h"

t_list *ft_listfunc(t_list *list, bool (*f_test)(t_list *, void *), void *ptr)
{
	while (list)
	{
		if (f_test(list, ptr))
			return (list);
		list = list->next;
	}
	return (NULL);
}
