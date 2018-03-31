//
// Created by Adrien PUSEL on 12/31/17.
//

#ifndef LIBT_D_LST_FUNCTION_H
# define LIBT_D_LST_FUNCTION_H

# include <stdlib.h>

/*
**  link // node
*/
typedef struct		s_dlink
{
	void			*content;
	size_t			content_size;
	struct s_dlink	*next;
	struct s_dlink	*prev;
}					t_dlink;

/*
**  head and end node
*/
typedef struct		s_d_list
{
	size_t			length;
	t_dlink			*where;
	t_dlink			*tail;
	t_dlink			*head;
}					t_dlist;

/*
**  function d lst
*/
t_dlink				*ft_dlist_link_new(void const *data, size_t content_size);

t_dlist				*ft_new_dlst(void);
int					ft_dlst_add_end(t_dlist *lst, void *data, size_t size_content);
int					ft_dlst_add_start(t_dlist *lst, void *data, size_t size_content);
int					ft_dlst_insert_atindex(t_dlist *lst, size_t position, void *data, size_t d);
void				ft_dlst_clear_all(t_dlist **list);

#endif
