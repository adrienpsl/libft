//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef LIBFT_LIBFT_LST_FUNCTION_H
# define LIBFT_LIBFT_LST_FUNCTION_H

# include <stdlib.h>

/*
**    structure
*/
typedef struct		s_sll_l
{
	void			*content;
	size_t			content_size;
	struct s_sll_l	*next;
}					*t_sll_l;

/*
**    construct ================================================================
*/
void  destroy_sll_l(t_sll_l *sll_l);
t_sll_l new_sll_l(void *content, size_t size);

/*
**    method ===================================================================
*/


/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/


#endif
