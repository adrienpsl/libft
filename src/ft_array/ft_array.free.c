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

#include <ft_mem.h>
#include <ft_log.h>

void ft_array$free(t_array **p_array)
{
	if (!p_array || !*p_array)
	{
		ft_log$message(F, L,
					   "ft_array$free arg ptr (null)",
					   EINVAL
		);
		return;
	}
	ft_array$clear(*p_array);
	ft_bzero(*p_array, sizeof(t_array));
	free(*p_array);
	*p_array = NULL;
}
