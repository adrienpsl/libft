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

#include "libft.h"

u_int16_t ft_bswap_16(u_int16_t value)
{
	return ((value & 0xff) << 8 | value >> 8);
}

u_int32_t ft_bswap_32(u_int32_t value)
{
	u_int32_t left;
	u_int32_t right;

	left = (u_int32_t)ft_bswap_16((u_int16_t)(value & 0xffff)) << 16;
	right = (u_int32_t)ft_bswap_16((u_int16_t)(value >> 16));
	return (left | right);
}

u_int64_t ft_bswap_64(u_int64_t value)
{
	u_int64_t left;
	u_int64_t right;

	left = (u_int64_t)ft_bswap_32((u_int32_t)(value & 0xffffffff)) << 32;
	right = (u_int64_t)ft_bswap_32((u_int32_t)(value >> 32));
	return (left | right);
}

