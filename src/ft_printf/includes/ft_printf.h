/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "ft_array.h"
# include "ft_buffer.h"
# define FORMAT_S (1)
# define FORMAT_D (1 << 1)
# define FORMAT_C (1 << 2)
# define FORMAT_U (1 << 3)
# define FORMAT_H (1 << 4)
# define FORMAT_L (1 << 5)
# define FORMAT_PADDING (1 << 6)
# define FORMAT_MINUS (1 << 7)
# define FORMAT_WILDCARD (1 << 8)
# define FORMAT_X (1 << 9)
# define FORMAT_0 (1 << 10)
# define FORMAT_10_BASE (FORMAT_H | FORMAT_L | FORMAT_D | FORMAT_C | FORMAT_U)
# define FT_PRINTF_PARCING_ERROR 100
# define FT_PRINTF_PARCING_ERROR_STRING "ft_printf error %[ unknown ]"
# define PF_MINUS 0
# define WILCARD 1
# define DOT  2
# define ZERO  3
# define LITTLE 4
# define TALL  5
# define STRING 6
# define DECIMAL 7
# define CHARACTER 8
# define HEXA  9
# define BINARY 10
# define UNSIGNED 11

typedef struct		s_pf_format
{
	unsigned long	minus: 1;
	unsigned long	wildard: 1;
	unsigned long	dot: 1;
	unsigned long	zero: 1;
	unsigned long	little: 1;
	unsigned long	tall: 1;
	unsigned long	string: 1;
	unsigned long	decimal: 1;
	unsigned long	character: 1;
	unsigned long	hexa: 1;
	unsigned long	binary: 1;
	unsigned long	unsign: 1;
	unsigned long	ptr: 1;
	unsigned long	b_hexa: 1;
	int				padding;
}					t_pf_format;

typedef struct		s_pf
{
	char			*format;
	char			*intern_str;
	char			*extern_buff;
	char			char_buffer[70];
	va_list			list;
	t_pf_format		format_bit;
	t_buffer		buff;
}					t_pf;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_sprintf(char *buffer, const char *format, ...);
int					pf__catch_format(t_pf *pf);
int					pf__get_number(t_pf *pf);
int					pf__get_str(t_pf *pf);
int					pf__print(t_pf *pf);
void				pf__utils_print(t_pf *pf, char *data, int size);
void				ft_pf_loop(t_pf *pf);

#endif
