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

void*	ftlog__null(char *file, int line)
{
	if (g_log > QUIET)
		ft_printf("%s:%d ptr (null)\n", file, line);
	return (NULL);
}

int		ftlog__int(char *file, int line)
{
	if (g_log > QUIET)
		ft_printf("%s:%d ptr (null)\n", file, line);
	return (-1);
}


int		ftlog__message(
	char *file, int line, char *message, int error_code)
{
	if (g_log > QUIET)
		ft_printf("%s:%d %s\n", file, line, message);
	return (error_code);
}
