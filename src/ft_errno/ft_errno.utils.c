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

# include "ft_errno.h"

static int g_errno;

int ft_errno_set(int errnum, int ret)
{
	if (errnum < 1 || errnum > FT_ERRNO_MAX)
		g_errno = 0;
	g_errno = errnum;
	return (ret);
}

int ft_errno_get()
{
	return (g_errno);
}
