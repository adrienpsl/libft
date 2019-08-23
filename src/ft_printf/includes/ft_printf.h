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

#ifndef PRINTF_HEADER_H
# define PRINTF_HEADER_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <cxxabi.h>

#include "ft_array.h"
#include "ft_buffer.h"
#include "libft_define.h"

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

/*
**	error
*/
#define FT_PRINTF_PARCING_ERROR 100
#define FT_PRINTF_PARCING_ERROR_STRING "ft_printf error %[ unknown ]"

#define  MINUS 0
#define  WILCARD 1
#define  DOT  2
#define  ZERO  3
#define  LITTLE 4
#define  TALL  5
#define  STRING 6
#define  DECIMAL 7
#define  CHARACTER 8
#define  HEXA  9
#define  BINARY 10
#define  UNSIGNED 11


typedef struct s_pf_format
{
	unsigned long minus: 1;
	unsigned long wildard: 1;
	unsigned long dot: 1;
	unsigned long zero: 1;
	unsigned long little: 1;
	unsigned long tall: 1;
	unsigned long string: 1;
	unsigned long decimal: 1;
	unsigned long character: 1;
	unsigned long hexa: 1;
	unsigned long binary: 1;
	unsigned long unsign: 1;
	int padding;
} t_pf_format;

typedef struct s_pf
{
	char *format;
	char char_buffer[70];
	char *intern_str;
	va_list list;
	t_buffer buff;
	char *extern_buff;
	t_pf_format format_bit;
} t_pf;


//int ft_sprintf(t_buffer *buffer, char *format, ...);
int ft_printf(const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);
int ft_sprintf(char *buffer, const char *format, ...);

// put title
int pf$catch_format(t_pf *pf);

int pf$get_number(t_pf *pf);
int pf$get_str(t_pf *pf);
int pf$print(t_pf *pf);

#endif
