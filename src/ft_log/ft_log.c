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

#include "ft_printf.h"
#include "includes/ft_log.h"

void ft_log(int level, const char *format, ...)
{
	va_list va_arg;

	if (level < g_log.level)
		return;
	ft_printf(
		"%s %s\x1b[0m",
		level_colors[level], level_names[level]
	);
	va_start(va_arg, format);
	ft_printf(format, va_arg);
	va_end(va_arg);
	ft_printf("\n");
}