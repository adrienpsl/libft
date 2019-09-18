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

#include "ft_systm.h"

char *ftsystm__find_in_directory(
	char *path,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	DIR *dir;
	struct dirent *dp;

	if (NULL != (dir = opendir(path)))
	{
		while ((dp = readdir(dir)))
		{
			if (0 < testing_function(binary_name, dp->d_name))
			{
				closedir(dir);
				return (ft_strdup(dp->d_name));
			}
		}
		closedir(dir);
	}
	return (NULL);
}