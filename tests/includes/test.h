//
// Created by adpusel on 2019-05-25.
//

#ifndef COMPACT_LIBFT_TEST_H
#define COMPACT_LIBFT_TEST_H

# include "stdio.h"

#define log_test(test_nb) printf("log : %s:%d: test: %d\n", __FILE__, __LINE__, test_nb);


void lib_clear_testbuff();
int ft_test_if_streq(char *res, char *test, char *where);
int lib_random_int(int limit);
int lib_cmp_testbuff(char *expected);


/*
**	print function
*/
void
lib_print_func(void *start, void (*f)(void *), size_t size_el, int length);
void lib_print_func_int(void *ptr);

//# define FT_PF_MODE 1

/*
**	teting stucture
*/

typedef struct		s_test
{
	int nb;
	char tata[22];
}					t_test_ft;


// lib ft


#endif //COMPACT_LIBFT_TEST_H
