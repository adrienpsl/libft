#ifndef LIBRARY_DLL_HEADER_H
#define LIBRARY_DLL_HEADER_H

# include <stdlib.h>
# include "dll_l_header.h"
# include "dll_c_header.h"

/*
**    structure
*/
typedef struct	s_dll
{
	size_t		length;
	t_dll_l		top;
	t_dll_l		end;
}				*t_dll;

/*
**    construct ================================================================
*/
void  destroy_dll(t_dll *dll);
t_dll new_dll();

/*
**    method ===================================================================
*/
t_dll_l dll_add(t_dll_l link, t_dll list);
t_dll_l dll_push(t_dll_l link, t_dll list);
t_dll_l dll_index(t_dll_l link, t_dll list, size_t index);

t_dll_l dll_drop_end(t_dll list);
t_dll_l dll_drop_top(t_dll list);
t_dll_l dll_drop_index(t_dll list, size_t index);

void dll_fill_list_circular(t_dll_c c_list, t_dll list, size_t lenght);


/*
**    utils ====================================================================
*/
t_dll_l dll_list_empty(t_dll_l link, t_dll list);
t_dll_l dll_drop_list_one(t_dll list);
t_dll_l get_good_link(size_t index, t_dll list);




/*
**    debug ====================================================================
*/
void dll_print_nb(t_dll lst);
void dll_print_nbrev(t_dll lst);
void dll_print_str(t_dll lst);
void dll_print_strrev(t_dll lst);


#endif //LIBRARY_DLL_HEADER_H
