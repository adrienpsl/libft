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

void     debug_print_tab_str(char **t)
{
	while (*t != NULL)
	{
	    ft_printf(*t);
	    ft_printf("\n");
	    t++;
	}
}

void     debug_print_tab_nb(int tab[], int lim)
{
	int i;
	
	i = 0;
	while (i < lim)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}