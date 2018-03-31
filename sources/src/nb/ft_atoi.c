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

#include "../../ft_library_header.h"

long	ft_atoi(const char *s)
{
	int i;
	long nb;
	long neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\r' || s[i] == '\n'
			|| s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		i++;
		neg = -neg;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return (nb * neg);
}
