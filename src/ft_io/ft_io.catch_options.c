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

#include <ft_str.h>
#include <errno.h>
#include <ft_log.h>
#include "stdio.h"

static int check(
	char **av,
	char *option_str,
	long *options_ptr,
	void (*f_usage)(char)
)
{
	if (NULL == av || NULL == *av)
		return (
			ft_log$message(F, L,
						   "ft_io$catch_options error: array av (null)",
						   EINVAL));
	else if (NULL == option_str || NULL == options_ptr)
		return (
			ft_log$message(F, L,
						   "ft_io$catch_options error: str / ptr ptr (null)",
						   EINVAL));
	else if (NULL == f_usage)
		return (
			ft_log$message(F, L,
						   "ft_io$catch_options error: func ptr (null)",
						   EINVAL));
	else
		return (0);
}

static int get_options(char *line, char *option_str, long *options_ptr,
	void (*f_usage)(char))
{
	int position;

	if (
		*line == '-'
		)
		line++;
	while (*line)
	{
		if (
			(position = ft_strchr(option_str, *line)) > -1
			)
		{
			*options_ptr |= (1 << position);
		}
		else
		{
			f_usage(*line);
			return (-1);
		}
		line++;
	}
	return (0);
}

int ft_io$catch_option(
	char **av,
	char *option_str,
	long *options_ptr,
	void (*f_usage)(char)
)
{
	int i;

	if (
		check(av, option_str, options_ptr, f_usage)
		)
		return (-1);
	i = 0;
	while (NULL != av[i])
	{
		if (
			!ft_str_cmp("--", av[i])
			)
			return (i + 1);
		if (
			av[i][0] != '-'
			)
			break;
		if (
			get_options(av[i] + 1, option_str, options_ptr, f_usage)
			)
			return (-1);
		i++;
	}
	return (i);
}
