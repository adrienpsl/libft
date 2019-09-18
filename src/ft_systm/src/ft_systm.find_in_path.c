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

char *ftsystm__find_in_path(
	char *paths_str,
	char *separators,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	char **paths;
	char *binary_path;
	int i;

	binary_path = NULL;
	if (NULL == (paths = ft_strsplit(paths_str, separators)))
		return (NULL);
	i = 0;
	while (NULL != paths[i])
	{
		if (NULL !=
			(binary_path = ftsystm__find_in_directory(
				paths[i], binary_name, testing_function)))
			break;
		i++;
	}
	ft_strsplit_free(&paths);
	return (binary_path);
}
