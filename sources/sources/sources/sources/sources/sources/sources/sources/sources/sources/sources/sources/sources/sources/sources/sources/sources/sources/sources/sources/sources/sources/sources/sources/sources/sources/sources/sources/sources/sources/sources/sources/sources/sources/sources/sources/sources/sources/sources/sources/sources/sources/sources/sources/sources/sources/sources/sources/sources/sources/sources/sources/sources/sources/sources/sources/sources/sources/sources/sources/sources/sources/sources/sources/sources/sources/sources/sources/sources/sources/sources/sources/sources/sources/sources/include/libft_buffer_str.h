//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef LIBFT_BUFFER_STR_H
# define LIBFT_BUFFER_STR_H

# include <stdlib.h>
# define BUFF_PRINTF 4096

typedef struct		s_buff_str
{
	char			data[BUFF_PRINTF + 1];
	size_t			remain_space;
}					t_buff_str;

/*
**	buffer str fuctions
*/
//void				ft_set_buff_str(t_buff_str *buff);
//void				ft_print_buff_str(t_buff_str *buff);
//int					ft_fill_buff_str(char *str, t_buff_str *buff);
//void				buff_set_or_print(char *for_print, t_buff_str *buff);
//void				ft_buff_addchar_str(char for_print, t_buff_str *buff);

#endif
