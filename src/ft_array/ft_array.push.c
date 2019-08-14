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
#include "ft_array.h"

int ft_array$push(t_array **p_array, void *element)
{
	if (
		!p_array
		|| !*p_array
		|| !element
		)
		return (ft_log$null(__FILE__, __LINE__));
	else
		return (ft_array$insert(p_array, element, (*p_array)->length));
}
