//#include "../../../../includes/src/argv_header.h"
//
//t_argv argv_test;
//
//void static init(char **av, int ac)
//{
//	argv_test = new_argv(ac, av);
//	//	print_tab_str(argv_test->available_options);
//}
//
//void static destroy()
//{
//	destroy_argv(&argv_test);
//	printf("------------------- \n");
//}
//
//static void test__1_() // check si destruct et construct work
//{
//	init(NULL, 0);
//	destroy();
//}
//
//static void test__2_() // test si pas d'argv
//{
//	init(NULL, 0);
//	char *str = "test 2 \n ";
//	(void) str;
//	destroy();
//}
//
//static void test__3_() // test print avec 1 argv test
//{
//	char **test = ft_strsplit("name_pro 1", ' ');
//	init(test, 2);
//
//	char *str = "test 3 \n test print avec 1 argv test";
//	(void) str;
//	char *test_str;
//
//	argv_get_next_argv(&test_str,argv_test);
//	printf("%s \n", test_str);
//	argv_get_next_argv(&test_str, argv_test);
//	printf("%s \n", test_str);
//	ft_free_split(&test);
//
//	destroy();
//}
//
//static void test__4_() // test print avec 2 argv test
//{
//	char **test = ft_strsplit("name_pro 1 2 ", ' ');
//	init(test, 3);
//
//	char *str = "test 3 \n test print avec 1 argv test";
//	(void) str;
//	char *test_str;
//
//
//	argv_get_next_argv(&test_str,argv_test);
//	printf("%s \n", test_str);
//	argv_get_next_argv(&test_str, argv_test);
//	printf("%s \n", test_str);
//	argv_get_next_argv(&test_str, argv_test);
//	printf("%s \n", test_str);
//
//	ft_free_split(&test);
//	destroy();
//}
//
//static void test__5_() // test print avec str 1 argv
//{
//	char **test = ft_malloc_protect(sizeof(char *) * 10);
//	test[0] = "programme";
//	test[1] = "-f";
//	test[2] = "-o";
//	test[3] = "12";
//	test[4] = "13";
//	test[5] = "-99";
//	test[6] = "1 2 3 4 5 6 7";
//	test[7] = "8 9 10 11";
//
//	init(test, 8);
//
//	char *str = "test 3 \n test print avec 1 argv test";
//	(void) str;
//
//	char *retour;
//	while (argv_get_next_argv(&retour, argv_test))
//	{
//		printf("%s \n", retour);
//	}
//	printf("%s \n", argv_test->taken_options);
//	free(test);
//	destroy();
//}
//
//static void test__6_(int ac, char **av) // test print avec str 1 argv
//{
//	init(av, ac);
//
//	char *str = "test 3 \n test print avec 1 argv test";
//	(void) str;
//
//	char *retour;
//	while (argv_get_next_argv(&retour, argv_test))
//	{
//		printf("%s \n", retour);
//	}
//	printf("%s \n", argv_test->taken_options);
//	destroy();
//}
//
//void  all_tdest_argv(int ac, char **av)
//{
//	test__1_();
//	test__2_();
//	test__3_();
//	test__4_();
//	test__5_();
//	test__6_(ac, av);
//}
//
//int main(int ac, char **av)
//{
//	(void) av;
//	printf("%d  \n", ac);
//	all_tdest_argv(ac, av);
//	return (0);
//}
