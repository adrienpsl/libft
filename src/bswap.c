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

uint16_t ft_bswap_16(uint16_t value)
{
	return ((value & 0xff) << 8 | value >> 8);
}

uint32_t ft_bswap_32(uint32_t value)
{
	uint32_t left;
	uint32_t right;

	left = (uint32_t)ft_bswap_16((uint16_t)(value & 0xffff)) << 16;
	right = (uint32_t)ft_bswap_16((uint16_t)(value >> 16));
	return (left | right);
}

uint64_t ft_bswap_64(uint64_t value)
{
	uint64_t left;
	uint64_t right;

	left = (uint64_t)ft_bswap_32((uint32_t)(value & 0xffffffff)) << 32;
	right = (uint64_t)ft_bswap_32((uint32_t)(value >> 32));
	return (left | right);
}

