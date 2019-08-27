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

#include <ft_printf.h>

int ftarray__func_print_str(void *p1, void *param)
{
	(void)param;
	ft_printf(" _%s_ ", *(char **)p1);
	return (0);
}

int ftarray__func_print_int(void *p1, void *param)
{
	(void)param;
	ft_printf("%d ", *(int *)p1);
	return (0);
}