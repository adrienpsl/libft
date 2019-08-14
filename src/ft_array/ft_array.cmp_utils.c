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
#include <ft_log.h>

int ft_array$cmp_int(void *p1, void *p2)
{
	int *a;
	int *b;

	if (!p1 || !p2)
	{
		return (
			ft_log$message(F, L,
						   "ft_array$cmp_int arg ptr (null)",
						   EINVAL
			)
		);
	}
	{
		a = p1;
		b = p2;
		return (!(*a == *b));
	}
}

int ft_array$cmp_str(void *p1, void *p2)
{
	char *a;
	char *b;

	if (!p1 || !p2)
	{
		return (
			ft_log$message(F, L,
						   "ft_array$cmp_str arg ptr (null)",
						   EINVAL
			)
		);
	}
	{
		a = p1;
		b = p2;
		return (!ft_streq(a, b));
	}
}
