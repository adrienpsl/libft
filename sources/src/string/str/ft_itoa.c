/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:53 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

static int		get_size(int n)
{
	int	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int		is_neg(int n, char *s)
{
	if (n < 0)
	{
		s[0] = '-';
		if (n == -2147483648)
		{
			s[1] = '2';
			n = -147483648;
		}
		n = -n;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*out;

	i = get_size(n);
	if (!(out = (char*)malloc((size_t)i + 1)))
		return (NULL);
	out[i] = 0;
	if (!n)
		out[0] = '0';
	n = is_neg(n, out);
	i--;
	while (n)
	{
		out[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (out);
}
