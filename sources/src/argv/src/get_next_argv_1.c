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

int is_remaining_argv(t_argv argv)
{
	return (argv->counter < argv->ac);
}

char *get_next_argv(t_argv argv)
{
	char *out_argv;

	out_argv = argv->av[argv->counter];
	argv->counter += 1;
	return (out_argv);
}

int argv_get_next_argv(char **out_argv, t_argv argv)
{

	if (argv_is_splitted(argv) == TRUE && end_of_split(argv) == FALSE)
		*out_argv = get_splitted_next_argv(argv);
	else if (is_remaining_argv(argv) == TRUE)
	{
		if (is_space_in_argv(argv) == TRUE)
			*out_argv = get_splitted_next_argv(argv);
		else
			*out_argv = get_next_argv(argv);
	}
	else
		return (0);
	return (1);
}