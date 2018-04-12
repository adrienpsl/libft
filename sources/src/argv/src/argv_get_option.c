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

int is_an_option(char *option, t_argv argv)
{

	if (option[0] == '-' && option[2] == '\0')
	{
		if (ft_strchr(OPTION, option[1]))
		{
			ft_charcat(argv->taken_options, option[1]);
			return (TRUE);
		}
	}
	else if (option[0] == '-' && ft_isdigit(option[1]))
	{
		return (FALSE);
	}
	else if (option[0] == '-')
		argv_error("no good option");
	return (FALSE);
}

void argv_get_option(t_argv argv)
{
	char *option;

	while (is_remaining_argv(argv) == TRUE)
	{
		option = get_next_argv(argv);
		if (is_an_option(option, argv) == FALSE)
		{
			argv->counter -= 1;
			break;
		}
	}
}