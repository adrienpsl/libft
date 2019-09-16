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

#include <ft_array.h>
#include <libft_define.h>
#include <ft_log.h>

int	static check(t_array *array, int from, int at)
{
	char *message;

	message = NULL;
	if (NULL == array)
		message = "ftarray__slice_and_remove array ptr (null)";
	else if (from >= array->length || at > array->length)
		message = "ftarray__slice_and_remove at / from > length";
	else if (from >= at)
		message = "ftarray__slice_and_remove at >= from";
	else if (at < 1 || from < 0)
		message = "ftarray__slice_and_remove at / from  < 0";
	return (message == NULL ?
			OK :
			ftlog__message(F, L, message, EINVAL));
}

t_array		*ftarray__slice_and_remove(
	t_array *array,
	int from,
	int at)
{
	t_array *new;

	if (OK != check(array, from, at))
		return (NULL);
	if (NULL == (new = ftarray__slice(array, from, at)))
		return (NULL);
	ftarray__remove_from(array, from, at);
	return (new);
}
