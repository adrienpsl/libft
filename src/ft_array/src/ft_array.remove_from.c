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

#include "libft.h"

int					static check(t_array *array, int from, int at)
{
	char *message;

	message = NULL;
	if (
		NULL == array
		)
		message = "ft_array$remove_from array ptr (null)";
	else if (
		at > array->length || from >= array->length
		)
		message = "ft_array$remove_from at / from > length";
	else if (
		from >= at
		)
		message = "ft_array$remove_from at >= from";
	else if (
		at < 1 || from < 0
		)
		message = "ft_array$remove_from at / from  < 0";
	return (message == NULL ?
			0 :
			ftlog__message(F, L, message, EINVAL)
	);
}

void	ftarray__remove_from(t_array *array, int from, int at)
{
	if (
		check(array, from, at)
		)
		return ;
	ft_memcpy(
		ftarray__at(array, from),
		ftarray__at(array, at),
		(array->length - at) * array->element_size
			 );
	array->length -= at - from;
}

