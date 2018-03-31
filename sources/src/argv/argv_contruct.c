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

void destroy_argv(t_argv *a)
{
	t_argv argv;

	if (a == NULL)
		return;
	argv = *a;
	if (argv->own_splitted_av)
		ft_free_split(&argv->own_splitted_av);
	free(argv);
}

t_argv new_argv(int ac, char **av)
{
	t_argv argv;

	//	no_argv(NO_ARGV);
	argv = ft_malloc_protect(sizeof(struct s_argv));
	ft_memset(argv, 0, sizeof(struct s_argv));
	argv->av = av;
	argv->ac = ac;
	argv->counter = 1;
	argv_get_option(argv);

	return (argv);
}