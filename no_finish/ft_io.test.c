
#include <libft.h>

int parse_itoa(uintmax_t origin_nb, char *base_str, char *out, int is_u);

int utils_itoa_base(uintmax_t nb, char *base, char *res, int is_u)
{
	char out[100];
	ft_memset(out, 0, 100);
	ft_itoa_base(nb, base, out, is_u);
	return (ft_memcmp(out, res, STRING_MODE));
}

int test_itoa_base()
{
	if (utils_itoa_base(0, "0123456789", "0", FALSE) ||
		utils_itoa_base(-42, "0123456789", "-42", FALSE) ||
		utils_itoa_base(42, "0123456789", "42", FALSE) ||
		utils_itoa_base(10, "0123456789", "10", FALSE) ||
		utils_itoa_base(1, "0123456789", "1", FALSE) ||

		// int
		utils_itoa_base(INT_MAX, "0123456789", "2147483647", FALSE) ||
		utils_itoa_base(INT_MIN, "0123456789", "-2147483648", FALSE) ||
		utils_itoa_base(UINT_MAX, "0123456789", "4294967295", TRUE) ||

		// long
		utils_itoa_base(LONG_MAX, "0123456789", "9223372036854775807", FALSE) ||
		utils_itoa_base(LONG_MIN, "0123456789", "-9223372036854775808", FALSE) ||
		utils_itoa_base(ULONG_MAX, "0123456789", "18446744073709551615", TRUE) ||

		// long long
		utils_itoa_base(LONG_LONG_MAX, "0123456789", "9223372036854775807", FALSE) ||
		utils_itoa_base(LONG_LONG_MIN, "0123456789", "-9223372036854775808", FALSE) ||
		utils_itoa_base(ULONG_LONG_MAX, "0123456789", "18446744073709551615", TRUE) ||

		utils_itoa_base(42, "01", "101010", TRUE) ||
		utils_itoa_base(42, "0123456789ABCDEF", "2A", TRUE)
	 )
		printf("test ft_io_itoa_base");

	return 0;
}

# define T 1
# define L (1 << 1)
# define A (1 << 2)
# define G (1 << 3)

int test_io_catch_options()
{
	// no option
	int ret;
	long options = 0;

	ret = ft_io_catch_options("", "", &options);
	if (ret || options)
		printf("test_io_catch_option_1 \n");

	ret = ft_io_catch_options("tatatllg", "tlag", &options);
	if (ret || !(options | A | T | L | G))
		printf("test_io_catch_option_2");

	options = 0;
	ret = ft_io_catch_options("tatatllg0", "tlag", &options);
	if (!ret || !(options | A | T | L | G))
		printf("test_io_catch_option_3");

	options = 0;
	ret = ft_io_catch_options("/l/l988c/lc", "tlag", &options);
	if (!(ret == '/') || options)
		printf("test_io_catch_option_4");
	return (0);
}

void test_ft_str_split(char *s, char **res, char *separators)
{
	char **split;

	split = ft_strsplit(s, separators);
	if (split && res && ft_strsplit_cmp(split, res))
	{
		g_test = 0;
		printf("err ft_strsplit : %s \n", s);
		ft_strsplit_print_test(split);
		ft_strsplit_print_test(res);
		g_test = 1;
	}
	ft_strsplit_free(&split);
}

void test_ft_str_split_add(char **split, char **res, char *add, int free, int *n)
{

	ft_strsplit_add(split, add, free);
	if (ft_strsplit_cmp(split, res))
	{
		printf("error test add : %d \n", *n);
		g_test = 0;
		ft_strsplit_print_test(split);
		printf("-- \n");
		ft_strsplit_print_test(res);
		g_test = 1;
	}
	(*n)++;
}

//void test_ft_str_split_remove(char **split, char **res, char *add, int *n)
//{
//	ft_str_split_remove(split, add);
//	if (ft_strsplit_cmp(split, res))
//	{
//		printf("error test delete: %d \n", *n);
//		g_test = 0;
//		ft_strsplit_print_test(split);
//		printf("-- \n");
//		ft_strsplit_print_test(res);
//		g_test = 1;
//	}
//
//	(*n)++;
//}

void passed_test()
{
	int n = 0;
	test_ft_str_split(NULL, NULL, " ");

	char **res_1 = { NULL };
	test_ft_str_split("", res_1, " ");

	char *res_2[2] = { "toto", NULL };
	test_ft_str_split("toto    ", res_2, " ");
	test_ft_str_split("         toto    ", res_2, " ");
	//
	char *res_3[3] = { "toto", "titi", NULL };
	test_ft_str_split("toto        titi", res_3, " ");
	test_ft_str_split("         toto titi         ", res_3, " ");

	char *res_4[100] = { "toto", "titi", "supre", "aeu", ",,,,", "aoeu", "iia", "'l'auh", "nnaou", "\033", NULL };
	test_ft_str_split("toto titi supre   aeu ,,,, aoeu iia 'l'auh nnaou   \033", res_4, " ");

	char *res_5[100] = { "lala", "lolol", "toto" };
	test_ft_str_split("lala;lolol;;toto", res_5, ";");

	/* test split add  empty ------------------------------------------------------------ */
	char *split_6[100] = { NULL };
	char *res_6[100] = { "toto" };
	test_ft_str_split_add(split_6, res_6, "toto", 0, &n);

	char *res_7[100] = { "toto", "toto" };
	test_ft_str_split_add(split_6, res_7, "toto", 0, &n);

	char *res_8[100] = { "toto", "toto", "aoeuaoeuaoeuaoeu aoeu" };
	test_ft_str_split_add(split_6, res_8, "aoeuaoeuaoeuaoeu aoeu", 0, &n);

	/* split delete ------------------------------------------------------------ */
//	char *res_9[100] = { "toto", "toto" };
//	test_ft_str_split_remove(split_6, res_9, "aoeuaoeuaoeuaoeu aoeu", &n);

//	char *res_10[100] = { "toto" };
//	test_ft_str_split_remove(split_6, res_10, "toto", &n);

//	char *res_11[100] = { NULL };
//	test_ft_str_split_remove(split_6, res_11, "toto", &n);

	test_itoa_base();
	test_io_catch_options();
}

void test_split_mix(char *split_1, char *split_2, char **split_res, int test)
{
	char **s1 = ft_strsplit(split_1, " ");
	char **s2 = ft_strsplit(split_2, " ");
	char **ret = ft_strsplit_mix(s1, s2, FREE_FIRST | FREE_SECOND);
	if (ft_strsplit_cmp(ret, split_res))
	{
		g_test = 0;
		printf("error test %d \n", test);
		ft_strsplit_print_test(split_res);
		ft_strsplit_print_test(ret);
		g_test = 1;
	}
//	printf(" \n");
//	ft_strsplit_print_test(split_res);
}

int test_ft_io()
{
	char *split_1_res[20] = {NULL};
	test_split_mix("", "", split_1_res, 1);

	char *split_2_res[20] = {"toto"};
	test_split_mix("toto", "", split_2_res, 2);

	char *split_3_res[20] = {"toto"};
	test_split_mix("", "toto", split_3_res, 3);

	char *split_4_res[20] = {"titi", "toto"};
	test_split_mix("titi", "toto", split_4_res, 4);

	char **split_5_res = ft_strsplit("titi super manger toto toto", " ");
	test_split_mix("titi super manger toto", "toto", split_5_res, 5);

	char **split_6_res = ft_strsplit("titi super manger toto ", " ");
	test_split_mix("titi super manger toto", "", split_6_res, 6);

	return 0;
}















