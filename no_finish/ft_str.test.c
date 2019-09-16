
#include <libft.h>

void	test_ft_str_search(char *str, char *searching, int res, int test)
{
	int ret;

	ret = ft_str_search(str, searching);
	if (ret != res)
		printf("%d error test :  \n", test);
}

void	test_ft_str_replace(char *str, char *searching, char *replacing, char *res_str, int test)
{
	char *out = NULL;

	out = ft_str_replace(str, searching, replacing, 0);
	if (res_str && ft_str_cmp(res_str, out))
	{
		printf("error test : %d /////////////////////\n", test);
		printf("%s -- %s \n", out, res_str);
	}
	if ((out && !res_str) || (!out && res_str))
		printf("one is null but not test: %s ,res:%s \n", out, res_str);
}

int test_ft_str()
{
	// str search
	test_ft_str_search(NULL, NULL, -1, 1);
	test_ft_str_search("toto", "tata", -1, 2);
	test_ft_str_search("aoeuau'", "ee", -1, 3);
	test_ft_str_search("toto", "toto", 0, 4);
	test_ft_str_search("eaeeoeeuaeeeu'", "eee", 9, 5);
	test_ft_str_search("eaeeoeeuaeeaeouhoe saoeuoaeu  osaeuhaoe  aoeoaeu sasoteutothoaeu  aotttoootoeuatotooeu u'",
					   "toto", 79, 6);
	test_ft_str_search("eaeeoeeuaeeaeouhoe saoeuoaeu  osaeuhaoe  aoeoaeu sasoteutothoaeu  aotttoootoeuatotooeu u'",
					   "tototo", -1, 7);
	test_ft_str_search("eaeeoeeuaeeaeouhoe saoeuoaeu  osaeuhaoe  aoeoaeu sasoteutothoaeu  aotttoootoeuatotooeu u'",
					   "to", 56, 8);

	// str replace
	test_ft_str_replace(NULL, NULL, NULL, NULL, 9);
	test_ft_str_replace("toto", "tata", "titi", NULL, 10);
	char test_11[20] = "toto";
	test_ft_str_replace(test_11, "toto", "titi", "titi", 11);

	char test_12[20] = "toto tata";
	test_ft_str_replace(test_12, "toto", "titi", "titi tata", 12);

	char test_13[200] = "to aa aa .. aoeu seouhoe  aoesu, aoeua,. /toto/oau aaou /ao,ua tata";
	test_ft_str_replace(test_13, "toto", "titi",
						"to aa aa .. aoeu seouhoe  aoesu, aoeua,. /titi/oau aaou /ao,ua tata", 13);

	char test_14[200] = "to aa aa .. aoeu seouhoe  aoesu, aoeua,. /toto/oau aaou /ao,ua tata";
	test_ft_str_replace(test_14, "nop", "titi",
						NULL, 14);

	char test_15[200] = "/totototo";
	test_ft_str_replace(test_15, "/totototo", "/foo",
						"/foo", 15);

	char test_16[200] = "/totototo";
	test_ft_str_replace(test_16, "/toto",
						"/fooaosuhaoseuhasouhasoehuaoneuhasouhaosehuasoeuasoehuansoeuhasnoeuhaoheuaonsehu",
						"/fooaosuhaoseuhasouhasoehuaoneuhasouhaosehuasoeuasoehuansoeuhasnoeuhaoheuaonsehutoto", 16);

	/* str char ------------------------------------------------------------- */
	char *find = "012345";
	ssize_t res_0, res_1, res_2;

	res_0 = ft_strchr(find, '0');
	res_1 = ft_strchr(find, '4');
	res_2 = ft_strchr(find, '9');

	if (res_0 != 0 || res_1 != 4 || res_2 != -1)
		printf("error strchr \n");


	/* str_join ------------------------------------------------------------- */
	char *a = "";
	char *b = "";
	char *res;

	res = ft_strjoin(a, b, 0);
	if (strcmp("", res))
		printf("join test 1 \n");
	free(res);

	res = ft_strjoin("super", "maison", 0);
	if (strcmp("supermaison", res))
		printf("join test 2 \n");
	free(res);

	//	/* reverse -------------------------------------------------------------- */
	//	char nothing[12] = "";
	//	char even[10] = "2211";
	//	char odd[10] = "33211";
	//
	//	ft_str reverse(nothing);
	//	ft_str_reverse(even);
	//	ft_str_reverse(odd);
	//
	//	if (strcmp(nothing, "") || strcmp(even, "1122") || strcmp(odd, "11233"))
	//		return 1;

	return 0;
}