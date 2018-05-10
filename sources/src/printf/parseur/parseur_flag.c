/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_into_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:49 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

static void		clean_str(char **s)
{
	if (**s == '.')
		(*s)++;
	if (**s == '*')
		(*s)++;
	while (ft_isdigit(**s))
	{
		(*s)++;
	}
}

static int		manage_dot(char **str, t_pf *pf)
{
	pf->op.dot = 1;
	if (*((*str) + 1) == '*')
	{
		pf->op.nb_dot = get_star_nxt_argv2(pf);
		if (pf->op.nb_dot < 0)
		{
			pf->op.dot = 0;
			pf->op.nb_dot = 0;
		}
	}
	else
		pf->op.nb_dot = ft_atoi((*str) + 1);
	clean_str(str);
	return (TRUE);
}

static int		manage_digit(char **str, t_op *option)
{
	option->nb_space = ft_atoi(*str);
	clean_str(str);
	return (TRUE);
}

static int		manage_fuckparseur(t_pf *pf)
{
	pf->specifier = **pf->s;
	(*pf->s)++;
	return (FALSE);
}

int				str_set_flag(t_pf *pf)
{
	if (**pf->s == '0')
		pf->op.zero = 1;
	else if (**pf->s == '.')
		return (manage_dot(pf->s, pf));
	else if (ft_isdigit(**pf->s))
		return (manage_digit(pf->s, &pf->op));
	else if (**pf->s == '*')
		pf->op.nb_space = get_star_nxt_argv(pf);
	else if (**pf->s == '#')
		pf->op.diez = 1;
	else if (**pf->s == '+')
		pf->op.plus = 1;
	else if (**pf->s == '-')
		pf->op.left = 1;
	else if (**pf->s == ' ')
		pf->op.space = 1;
	else if (**pf->s == '&')
		return (get_color(pf));
	else
		return (manage_fuckparseur(pf));
	(*pf->s)++;
	return (TRUE);
}
