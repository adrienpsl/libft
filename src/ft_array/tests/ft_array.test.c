#include "../includes/ft_array.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <libft.h>



int my_rand(int limit)
{
	return rand() % limit + 1;
}

void test_ft_array()
{
	//	// test init and destroy
	//	test_ft_array_init((t_test) {
	//	.test_nb = 1,
	//	.nb_element = 10,
	//	.size_element = sizeof(int),
	//	.int_arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	//	});

	// test array add string
	t_array *test_add_string = ft_array_init(1, sizeof(char *));
	for (int i = 0; i < 2000; ++i)
	{
		char *a = "tata";
		ft_array$push(&test_add_string, a);
	}
	//	ft_array_func(test_add_string, ft_array_func_print$str, NULL);
	ft_array_free(&test_add_string);

	// test with add at the middle bottom ...
	t_array *test_add_random = ft_array_init(2000, sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < 10000; ++i)
	{
		ft_array$push_at(&test_add_random, &i, my_rand(2000));
	}
	//	ft_array_func(test_add_random, ft_array_func_print$int, NULL);
	//	printf("\n%d \n", test_add_random->length);
	ft_array_free(&test_add_random);


	/* test remove ---------------------------------------------------------- */
	// test start
	t_array *test_delete = ft_array_init(1, sizeof(char *));
	for (int i = 0; i < 2000; ++i)
	{
		char *a = "tata";
		ft_array$push(&test_delete, a);
	}
	for (int i = 0; i < 2000; ++i)
	{
		ft_array_remove(test_delete, 0);
	}
	//	printf("\n%d \n", test_delete->length);
	//	ft_array_func(test_delete, ft_array_func_print$int, NULL);
	ft_array_free(&test_delete);

	test_delete = ft_array_init(2000, sizeof(int));
	for (int i = 0; i < 200; ++i)
	{
		ft_array$push(&test_delete, &i);
	}
	for (int i = 0; i < 10; ++i)
	{
		ft_array_remove(test_delete, 0);
	}

	for (int i = 0; i < 190; ++i)
	{
		ft_array_remove(test_delete, test_delete->length - 1);
	}
//	g_log_errors = 0;
	// test si il en reste
	if (ft_array_remove(test_delete, test_delete->length - 1) != -1)
		printf("error ret ft_array_remove \n");

	// je le remplie avec 100 nb
	for (int i = 0; i < 100; ++i)
	{
		ft_array$push(&test_delete, &i);
	}

	for (int i = 0; i < 10000; ++i)
	{
		ft_array_remove(test_delete, my_rand(100));
	}
	ft_array_remove(test_delete, 0);
//	g_log_errors = 1;
	if (test_delete->length)
	    printf("ft_array_remove delete last test \n");
	ft_array_func(test_delete, ft_array_func_print$int, NULL);
}