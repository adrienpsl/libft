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

#include "../../../ft_library_header.h"

/*
**    if space into argv, split argv[ac] in : own_splitted_av \\ +1 counter
*/

int is_space_in_argv(t_argv argv)
{
	if (ft_strchr(argv->av[argv->counter], ' '))
	{
		argv->own_splitted_av = ft_strsplit(argv->av[argv->counter], ' ');
		argv->counter += 1;
		return (TRUE);
	}
	return (FALSE);
}

/*
**    get the split argv
*/

char *get_splitted_next_argv(t_argv argv)
{
	char *out_str;

	out_str = argv->own_splitted_av[argv->counter_osa];
	argv->counter_osa += 1;
	return (out_str);
}

int argv_is_splitted(t_argv argv)
{
	return (argv->own_splitted_av != NULL);
}

/*
**    free split argv if needed
*/

int end_of_split(t_argv argv)
{
	if (argv->own_splitted_av[argv->counter_osa] == NULL)
	{
		ft_free_split(&argv->own_splitted_av);
		argv->own_splitted_av = NULL;
		argv->counter_osa = 0;
		return (TRUE);
	}
	return (FALSE);
}