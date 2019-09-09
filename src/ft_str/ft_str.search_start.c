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

// search take a function witch will return if it in all string or by the
// start

int ft_str_search(char *src, char *searching)
{
	int i;
	int y;

	if (!src || !searching)
		return (-1);
	i = 0;
	while (src[i])
	{
		if (src[i] == searching[0])
		{
			y = 1;
			while (src[i + y] && searching[y]
				   && src[i + y] == searching[y])
				y++;
			if (searching[y] == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

int ftstrsearch__start(char *src, char *searching)
{
	int i;

	if (!src || !searching)
		return (-1);
	i = 0;
	while (src[i] && searching[i] && src[i] == searching[i])
	{
		i++;
	}
	if (searching[i] == 0)
		return (i);
	return (-1);
}

int check(char *current, char *searching)
{
	if (
		NULL == current || NULL == searching
		)
		return (
			ftlog__message(F, L, "ftstr__search_start input (null)",
						   EINVAL)
		);
	else
		return (
			0
		);
}

int ftstr__search_start(char *current, char *searching, int param)
{
	int i;

	i = 0;
	if (
		check(current, searching)
		)
		return (-1);
	while (
		current[i] && searching[i]
		&& current[i] == searching[i]
		)
		i += 1;
	if (
		FTSTR__SEARCH_START_STRICT == param
		&& (searching[i] == '\0' && current[i] == '\0')
		)
		return (i);
	else if (
		FTSTR__SEARCH_START_PARTIAL == param
		&& current[i] == '\0'
		)
		return (i);
	else
		return (-1);
}