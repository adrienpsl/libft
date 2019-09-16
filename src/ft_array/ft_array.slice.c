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

int static check(t_array *array, int from, int at)
{
	char *message;

	message = NULL;
	if (
		NULL == array
		)
		message = "ftarray__slice array ptr (null)";
	else if (
		from >= array->length || at > array->length
		)
		message = "ftarray__slice at / from > length";
	else if (
		from >= at
		)
		message = "ftarray__slice at >= from";
	else if (
		at < 1 || from < 0
		)
		message = "ftarray__slice at / from  < 0";
	return (message == NULL ?
			0 :
			ftlog__message(F, L, message, EINVAL)
	);
}

t_array *ftarray__slice(t_array *array, int from, int at)
{
	if (
		check(array, from, at)
		)
		return (NULL);
	return (
		ftarray__init_data(
			ftarray__at(array, from),
			at - from,
			array->element_size
						  )
	);
}
