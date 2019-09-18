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

#include <ft_log.h>

#include "ft_systm.h"

static int check(
	char *path,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	if (NULL == path || NULL == binary_name || NULL == testing_function)
	{
		return (ftlog__message(F, L,
			"ftsystm__find_in_directory"
			"one argument is null", EINVAL));
	}
	return (OK);
}

char *ftsystm__find_in_directory(
	char *path,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	DIR *dir;
	struct dirent *dp;

	if (OK != check(path, binary_name, testing_function))
		return (NULL);
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