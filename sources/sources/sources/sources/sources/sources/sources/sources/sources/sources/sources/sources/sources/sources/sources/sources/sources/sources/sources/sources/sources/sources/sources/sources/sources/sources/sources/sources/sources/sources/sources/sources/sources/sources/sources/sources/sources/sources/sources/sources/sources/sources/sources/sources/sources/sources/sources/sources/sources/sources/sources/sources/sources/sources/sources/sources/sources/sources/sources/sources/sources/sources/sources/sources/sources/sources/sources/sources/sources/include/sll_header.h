#ifndef LIBRARY_SLLLHEADER_H
#define LIBRARY_SLLLHEADER_H

# include <stdlib.h>
# include "sll_l_header.h"

/*
**    structure
*/
typedef struct		s_sll
{
	size_t			lenght;
	t_sll_l 		top;
	t_sll_l			tail;
}					*t_sll;

/*
**    construct ================================================================
*/
void  destroy_sll(t_sll *l);
t_sll new_sll();

/*
**    method ===================================================================
*/
t_sll_l sll_add(t_sll_l link, t_sll list);
t_sll_l sll_drop_link(t_sll_l link, t_sll list);
t_sll_l sll_drop_index(t_sll_l link, t_sll list);


/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/
void sll_print_str(t_sll list);
void sll_print_str_link(t_sll_l link);


#endif //LIBRARY_SLLLHEADER_H
