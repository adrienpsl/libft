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

#include <ft_systm.h>

int ftsystm__test_file(char *path, char *name, char *argv)
{
	if (!path || !name || !argv)
		return (-1);
	if (OK != access(path, F_OK))
	{
		ft_printf("%s: no such file or directory: %s\n", name, argv);
		return (-1);
	}
	if (OK != access(path, R_OK))
	{
		ft_printf("%s: permission denied: %s\n", name, argv);
		return (-1);
	}
	return (OK);
}