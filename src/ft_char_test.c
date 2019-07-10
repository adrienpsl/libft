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

int ft_char_test(int c, int test_type)
{
	if (test_type == FT_CHAR_ASCII)
		return (c > 0 && c <= 127);
	if (test_type == FT_CHAR_DIGIT)
		return (c >= '0' && c <= '9');
	if (test_type == FT_CHAR_ALPHA)
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	if (test_type == FT_CHAR_ALPHA_DIGIT)
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
			   (c >= 'A' && c <= 'Z');
	if (test_type == FT_CHAR_SPACE)
		return (c == ' ' || c == '\t');
	else
		return (c == test_type);
}
