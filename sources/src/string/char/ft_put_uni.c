/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:06 by adpusel           #+#    #+#             */
/*   Updated: 2017/10/19 10:48:06 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

void	ft_put_uni(int c)
{
	char tab[5];

	if (c <= 126)
		tab[0] = c;
	else if (c <= 0x7FF)
	{
		tab[0] = ((c >> 6) & 0x1F) + 0xC0;
		tab[1] = (c & 0x3F) + 0x80;
		tab[2] = 0;
	}
	else if (c < 0xFFFF)
	{
		tab[0] = ((c >> 12) & 0xF) + 0xE0;
		tab[1] = ((c >> 6) & 0x3F) + 0x80;
		tab[2] = (c & 0x3F) + 0x80;
	}
	else if (c < 0x1FFFF)
	{
		tab[0] = ((c >> 18) & 0x7) + 0xF0;
		tab[1] = ((c >> 12) & 0x3F) + 0x80;
		tab[2] = ((c >> 6) & 0x3F) + 0x80;
		tab[3] = (c & 0x3F) + 0x80;
	}
	ft_putstr(tab);
}
