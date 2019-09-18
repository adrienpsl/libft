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

#ifndef FT_SYSTM
#define FT_SYSTM

/*
** External  -------------------------------------------------------------------
*/
# include <dirent.h>
# include <stdio.h>

/*
**	Internal  ------------------------------------------------------------------
*/
# include <ft_str.h>
# include <ft_strsplit.h>
# include <libft_define.h>

/*
**	Prototypes  ----------------------------------------------------------------
*/

char *ftsystm__find_in_directory(
	char *path,
	char *binary_name,
	int (*testing_function)(char *, char *));

char *ftsystm__find_in_path(
	char *paths_str,
	char *separators,
	char *binary_name,
	int (*testing_function)(char *, char *));

#endif
