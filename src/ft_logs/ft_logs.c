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

void ft_log(char *log)
{
	if (g_log_log)
	{
		write(1, log, ft_strlen(log));
		write(1, "\n", 1);
	}
}

void ft_logerror(char *errstr)
{
	if (g_log_errors)
	{
		write(2, errstr, ft_strlen(errstr));
		write(2, "\n", 1);
	}
}