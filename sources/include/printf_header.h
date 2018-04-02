/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_char_into_str.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adpusel <adpusel@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/10/19 10:48:07 by adpusel		   #+#	#+#			 */
/*   Updated: 2017/11/16 12:45:49 by adpusel		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
#include <cxxabi.h>

# define BUFF_SIZE 512

typedef union
{
	double d;
	struct
	{
		uint64_t mantisa : 52;
		uint64_t exponent : 11;
		uint64_t sign : 1;
	} parts;
} u_double;

typedef struct		s_buff
{
	char			data[BUFF_SIZE + 1];
	size_t			remain_space;
}					t_buff;

typedef struct		s_int
{
	char			nb_s[300];
	char			first_char[3];
	uint8_t			neg:1;
}					t_int;

typedef struct		s_text
{
	wchar_t			*u_out;
	char			*out;
	long			precision;
	uint8_t			uni:1;
}					t_text;

typedef struct		s_op
{
	long			nb_dot;
	long			nb_space;
	char			length;
	char			color;
	char			police;
	uint8_t			putain_de_char:1;
	uint8_t			zero:1;
	uint8_t			dot:1;
	uint8_t			diez:1;
	uint8_t			left:1;
	uint8_t			plus:1;
	uint8_t			space:1;
}					t_op;

typedef struct		s_pf
{
	t_buff			buff;
	t_op			op;
	t_int			pf_int;
	t_text			text;
	wchar_t			uni_nul[8];
	char			null[8];
	char			specifier;
	uint64_t		data;
	long			retour;
	va_list			*ap;
	char			**s;
}					t_pf;

/*
**	buffer function /////////////////////////
*/
void				ft_print_buff(t_buff *buff);
int					ft_fill_buff(char *str, t_buff *buff);
void				ft_set_buff(t_buff *buff);
void				buff_set_or_print(char *for_print, t_pf *pf);
void				buff_set_or_print_char(char for_print, t_pf *pf);

/*
**	head printf /////////////////////////////////
*/
long				ft_printf(char *str, ...);

/*
**	head data
*/
void				manage_before_printer(t_pf *pf);

/*
**	utils data
*/
void				check_if_null_data(t_pf *pf);

/*
**	======= parseur ============================================================
*/
int					ft_printf_parseur(t_pf *pf);
int					str_set_flag(t_pf *pf);

/*
**	utils
*/
int					get_maj(t_pf *pf);
int					get_color(t_pf *pf);

/*
**	-------- int --------------------------------
*/
void				manage_decimal(t_pf *pf);

/*
**	unsigned int
*/
void				manage_unsigned(t_pf *pf);

/*
**	octal style
*/
void				manage_octal(t_pf *pf);

/*
**	hexa style
*/
void				manage_hexa(t_pf *pf);

/*
**	binary style
*/
void				manage_binaire(t_pf *pf);

/*
**	ptr style
*/
void				manage_ptr(t_pf *pf);

/*
**	unsigned utils
*/
void				convert_base_fill_unsigned(t_pf *pf, char *base);
void				set_lenght_unsigned(t_pf *pf);

/*
**	manage double
*/
void				manage_float(t_pf *pf);

/*
**	================= text =======================
*/
size_t				strlen_uni(wchar_t *s, int precision);
void				put_uni_into_tab(int c, char *tab, int precision);
size_t				size_uni(wchar_t c, int precision);

/*
**  str style
*/
void				manage_str(t_pf *pf);

/*
**	str uni style
*/
void				manage_str_big(t_pf *pf);

/*
**	char style
*/
void				manage_char(t_pf *pf);

/*
**	uni char style
*/
void				manage_CHAR(t_pf *pf);

/*
**	n option style
*/
void				manage_n(t_pf *pf);

/*
**	percent style
*/
void				manage_percent(t_pf *pf);

/*
**	fuck style
*/
void				manage_fuck(t_pf *pf);

/*
**	main_utils //////////////////////////////
*/
long				get_star_nxt_argv(t_pf *pf);
void				set_null_pf(t_pf *pf);
long				get_star_nxt_argv2(t_pf *pf);

/*
**	printer
*/
void				manage_printer(t_pf *pf);
void				printer_space(t_pf *pf);
void				printer_precision(t_pf *pf);
void				printer_value(t_pf *pf);

/*
**	utils printer
*/
void			put_color(t_pf *pf);

#endif
