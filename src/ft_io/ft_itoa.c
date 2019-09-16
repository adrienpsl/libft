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

# include "ft_io.h"
# include "ft_mem.h"

int					ft_itoa_unsigned(uintmax_t origin_nb, const char *base_str, char *out)
{
	int i;
	size_t base;
	uintmax_t nb;

	base = ft_strlen(base_str);
	i = 0;
	nb = origin_nb;
	while (nb /= base)
		i++;
	nb = origin_nb;
	while (i > -1)
	{
		out[i] = base_str[nb % base];
		nb /= base;
		i--;
	}
	return (0);
}

int					ft_itoa_base(uintmax_t origin_nb, const char *base_str, char *out, int is_u)
{
	int neg;
	long long nb;

	if (origin_nb == 0)
	{
		ft_memcpy(out, "0", 2);
		return (1);
	}
	if (is_u)
		return ft_itoa_unsigned(origin_nb, base_str, out);
	else
	{
		nb = origin_nb;
		neg = nb < 0 ? 1 : 0;
		if (neg)
		{
			nb = -nb;
			out[0] = '-';
		}
		return ft_itoa_unsigned(nb, base_str, neg ? out + 1 : out);
	}
}