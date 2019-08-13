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

#include <ft_log.h>
#include <ft_printf.h>
#include <ft_errno.h>

int ft_log$null(char *file, int line)
{
	if (g_log > QUIET)
		ft_printf("%s:%d ptr (null)\n", file, line);
	return (ft_errno_set(EINVAL, -1));
}

int ft_log$message(char *file, int line, char *message, int error_code)
{
	if (g_log > QUIET)
		ft_printf("%s:%d %s\n", file, line, message);
	return (ft_errno_set(error_code, -1));
}