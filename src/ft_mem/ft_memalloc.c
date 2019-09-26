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
#include <ft_str.h>
#include <ft_printf.h>
#include "ft_mem.h"

void	*ft_memalloc(size_t size)
{
	void *res;

	res = malloc(size);
	if (res == NULL)
	{
		if (g_log > QUIET)
			ft_printf("ft_memalloc : error in memory allocation\n");
		return (NULL);
	}
	ft_memset(res, 0, size);
	return (res);
}
