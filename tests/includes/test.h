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
int test_ft_char();
int test_ft_memory();
int test_ft_list();
int test_ft_str();
int test_ft_io();
int test_ft_buffer();
int test_ft_array();


// printf
int test_ft_printf();



#endif //COMPACT_LIBFT_TEST_H
