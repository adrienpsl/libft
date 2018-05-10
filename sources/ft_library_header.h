#ifndef LIBRARY_FT_LIBRARY_HEADER_H
# define LIBRARY_FT_LIBRARY_HEADER_H

/*
**    printF
*/
# include "include/printf_header.h"

/*
**	for more clarter
*/
# include "include/libft_define.h"

/*
**	buffer_str
*/
# include "include/libft_buffer_str.h"

/*
**  memory function
*/
# include "include/libft_memory_function.h"


/*
**  text function
*/
# include "include/libft_str_function.h"

/*
**  text nb
*/
# include "include/libft_nb_function.h"

/*
**    List ===========================================================
*/

/*
**  simple linked list link
*/
# include "include/sll_l_header.h"

/*
**    simple linked list
*/
# include "include/sll_header.h"

/*
**	double linked list link
*/
# include "include/dll_l_header.h"

/*
**    double linked link
*/
# include "include/dll_header.h"

/*
**	double linked circular list
*/
# include "include/dll_c_header.h"

/*
**    end list ========================================================
*/

/*
**    debug
*/
#include "include/libft_debug.h"

/*
**    object argv
*/
# include "include/argv_header.h"

void			ft_quick_sort(int *tab, int start, int end);
void ft_quick_sort_dll(t_dll_l start, t_dll_l end, t_dll list );


#endif
