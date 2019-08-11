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

#include "ft_io.h"
/*
 * return the illegal option
 * */
int ft_io_catch_options(char *av_string, char *str_option, long *options)
{
	int ret;
	static int position;

	position = 0;
	while (av_string[position]
		   && (ret = ft_strchr(str_option, av_string[position])) > -1)
	{
		*options |= (1 << ret);
		position++;
	}
	if (ret == -1)
		return (av_string[position]);
	return (0);
}
