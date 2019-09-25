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

static int	check(
	char *paths_str,
	char *separators,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	if (NULL == paths_str
		|| NULL == separators
		|| NULL == binary_name
		|| NULL == testing_function)
	{
		return (ftlog__message(F, L,
			"ftsystm__find_in_path"
			"are some arguments (null)", EINVAL));
	}
	return (OK);
}

/*
**	return fresh str
*/
char		*ftsystm__find_in_path(
	char *paths_str,
	char *separators,
	char *binary_name,
	int (*testing_function)(char *, char *))
{
	char	**paths;
	char	*binary_path;
	int		i;

	if (OK != check(paths_str, separators, binary_name, testing_function))
		return (NULL);
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
	binary_path = ft_strjoin("/", binary_path, 2);
	binary_path = ft_strjoin(paths[i], binary_path, 2);
	ft_strsplit_free(&paths);
	return (binary_path);
}
