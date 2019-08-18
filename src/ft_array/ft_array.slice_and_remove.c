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
		message = "ft_array$slice_and_remove array ptr (null)";
	else if (
		from >= array->length || at > array->length
		)
		message = "ft_array$slice_and_remove at / from > length";
	else if (
		from >= at
		)
		message = "ft_array$slice_and_remove at >= from";
	else if (
		at < 1 || from < 0
		)
		message = "ft_array$slice_and_remove at / from  < 0";
	return (message == NULL ?
			0 :
			ft_log$message(F, L, message, EINVAL)
	);
}

t_array *ft_array$slice_and_remove(t_array *array, int from, int at)
{
	t_array *new;

	if (
		check(array, from, at)
		)
		return (NULL);
	if (
		NULL == (new = ft_array$slice(array, from, at))
		)
		return (NULL);
	ft_array$remove_from(array, from, at);
	return (new);
}
