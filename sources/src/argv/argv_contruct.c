/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_contruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:11:25 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

void	destroy_argv(t_argv *a)
{
	t_argv argv;

	if (a == NULL)
		return ;
	argv = *a;
	if (argv->own_splitted_av)
		ft_free_split(&argv->own_splitted_av);
	free(argv);
}

t_argv	new_argv(int ac, char **av)
{
	t_argv argv;

	argv = ft_malloc_protect(sizeof(t_argv_00));
	ft_memset(argv, 0, sizeof(t_argv_00));
	argv->av = av;
	argv->ac = ac;
	argv->counter = 1;
	argv_get_option(argv);
	return (argv);
}
