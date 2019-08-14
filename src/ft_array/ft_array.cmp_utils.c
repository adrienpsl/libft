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

#include <ft_str.h>

int ft_array_cmp$int(void *p1, void *p2)
{
	int *a;
	int *b;

	a = p1;
	b = p2;
	return (!(*a == *b));
}

int ft_array_cmp$str(void *p1, void *p2)
{
	char *a;
	char *b;

	a = p1;
	b = p2;
	return (!ft_streq(a, b));
}
