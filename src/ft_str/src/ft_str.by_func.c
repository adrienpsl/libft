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

#include <libft.h>

char	*ftstr_by_func(
	char *str,
	int (*testing_function)(char, void *),
	void *param)
{
	if (str == NULL || testing_function == NULL)
		return (ftlog__null(F, L));
	while (*str != '\0')
	{
		if (testing_function(*str, param))
			return (str);
		str += 1;
	}
	return (NULL);
}

/*
**	return the where there are the match or -1
*/

int		ftstr_func_int(
	char *str,
	int (*testing_function)(char, void *),
	void *param)
{
	int i;

	if (str == NULL || testing_function == NULL)
		return (ftlog__int(F, L));
	i = 0;
	while (str[i] != '\0')
	{
		if (testing_function(str[i], param))
			return (i);
		i += 1;
	}
	return (-1);
}
