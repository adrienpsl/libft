#include "../sources/ft_library_header.h"

//void static
//init(t_dll_c test_dll_c_, t_dll_l link1, t_dll_l link2, t_dll_l link3,
// t_dll_c test_dll_c)
//{
//	test_dll_c = new_dll_c();
//	int a = 1;
//	int b = 2;
//	int c = 3;
//
//	link1 = new_dll_l(&a, sizeof(int));
//	link2 = new_dll_l(&b, sizeof(int));
//	link3 = new_dll_l(&c, sizeof(int));
//}
//
//void static destroy(t_dll_c test_dll_c_)
//{
//	destroy_dll_c(&test_dll_c_);
//}

static void test__1_() // check si destruct et construct work
{
	t_dll_c test_list = new_dll_c();
	destroy_dll_c(&test_list);
}

static void test__2_() //  el null
{
	t_dll_c test_list = new_dll_c();

	char *str = "test 2 \n test de el null";
	(void) str;

	dll_c_push_link(NULL, test_list);

	destroy_dll_c(&test_list);
}

static void test__3_() // test avec un link
{
	t_dll_c test_list = new_dll_c();

	int a = 1;
	t_dll_l link1 = new_dll_l(&a, sizeof(int));

	char *str = "test 3 \n test de test avec un link";
	(void) str;

	dll_c_push_link(link1, test_list);
	destroy_dll_c(&test_list);
}

static void test__4_() // test avec deux el
{
	t_dll_c test_list = new_dll_c();

	int a = 1;
	int b = 2;
	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));

	char *str = "test 4 \n test avec deux el";
	(void) str;

	dll_c_push_link(link1, test_list);
	dll_c_push_link(link2, test_list);

	dll_c_print_lst(test_list);
	dll_c_print_lst_reverse(test_list);
	destroy_dll_c(&test_list);
	printf("----------------------- \n");
}

static void test__5_() // test avec trois el
{
	t_dll_c test_list = new_dll_c();

	int a = 1;
	int b = 2;
	int c = 3;
	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));
	t_dll_l link3 = new_dll_l(&c, sizeof(int));

	char *str = "test 4 \n test avec deux el";
	(void) str;

	dll_c_push_link(link1, test_list);
	dll_c_push_link(link2, test_list);
	dll_c_push_link(link3, test_list);

	dll_c_print_lst(test_list);
	dll_c_print_lst_reverse(test_list);
	destroy_dll_c(&test_list);
	printf("----------------------- \n");
}

static void test__6_() // drop link;
{
	t_dll_c test_list = new_dll_c();

	dll_c_drop_link(test_list);

	destroy_dll_c(&test_list);
}

static void test__7_() // drop link 1;
{
	t_dll_c test_list1 = new_dll_c();
	t_dll_c test_list2 = new_dll_c();

	int a = 1;

	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2;

	dll_c_push_link(link1, test_list1);

	link2 = dll_c_drop_link(test_list1);

	destroy_dll_l(&link2);
	destroy_dll_c(&test_list1);
	destroy_dll_c(&test_list2);
}

static void test__8_() // drop de 2 link;
{
	t_dll_c test_list1 = new_dll_c();
	t_dll_c test_list2 = new_dll_c();

	int a = 1;
	int b = 2;

	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));
	t_dll_l tmp;

	dll_c_push_link(link1, test_list1);
	dll_c_push_link(link2, test_list1);

	tmp = dll_c_drop_link(test_list1);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);
	destroy_dll_l(&tmp);

	tmp = dll_c_drop_link(test_list1);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);
	destroy_dll_l(&tmp);

	destroy_dll_c(&test_list1);
	destroy_dll_c(&test_list2);
	printf("----------------------- \n");
}

static void test__9_() // drop de 3 link;
{
	t_dll_c test_list1 = new_dll_c();
	t_dll_c test_list2 = new_dll_c();

	int a = 1;
	int b = 2;
	int c = 3;

	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));
	t_dll_l link3 = new_dll_l(&c, sizeof(int));
	t_dll_l tmp;

	dll_c_push_link(link1, test_list1);
	dll_c_push_link(link2, test_list1);
	dll_c_push_link(link3, test_list1);

	tmp = dll_c_drop_link(test_list1);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);
	destroy_dll_l(&tmp);

	tmp = dll_c_drop_link(test_list1);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);
	destroy_dll_l(&tmp);

	tmp = dll_c_drop_link(test_list1);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);
	destroy_dll_l(&tmp);

	destroy_dll_c(&test_list1);
	destroy_dll_c(&test_list2);
	printf("----------------------- \n");
}

static void test__10_() // drop et repush  de 3 link;
{
	t_dll_c test_list1 = new_dll_c();
	t_dll_c test_list2 = new_dll_c();

	int a = 1;
	int b = 2;
	int c = 3;

	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));
	t_dll_l link3 = new_dll_l(&c, sizeof(int));
	t_dll_l tmp;

	dll_c_push_link(link1, test_list1);
	dll_c_push_link(link2, test_list1);
	dll_c_push_link(link3, test_list1);

	tmp = dll_c_drop_link(test_list1);
	dll_c_push_link(tmp, test_list2);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);

	tmp = dll_c_drop_link(test_list1);
	dll_c_push_link(tmp, test_list2);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);

	tmp = dll_c_drop_link(test_list1);
	dll_c_push_link(tmp, test_list2);
	printf("%d \n", dll_l_get_int(tmp));
	dll_c_print_lst(test_list1);
	dll_c_print_lst(test_list2);

	destroy_dll_c(&test_list1);
	destroy_dll_c(&test_list2);
	printf("----------------------- \n");
}

static int func(int a, int b)
{
	return (a == b);
}

static void test__11_() // test la fonction iter_int
{

	t_dll_c test_list1 = new_dll_c();
	t_dll_c test_list2 = new_dll_c();

	int a = 1;
	int b = 2;
	int c = 3;

	t_dll_l link1 = new_dll_l(&a, sizeof(int));
	t_dll_l link2 = new_dll_l(&b, sizeof(int));
	t_dll_l link3 = new_dll_l(&c, sizeof(int));

	dll_c_push_link(link1, test_list1);
	if (dll_l_iter_int(test_list1, 1, &func))
		printf("ok 1\n");

	dll_c_push_link(link2, test_list1);
	if (dll_l_iter_int(test_list1, 1, &func))
		printf("ok 2-1 ");
	if (dll_l_iter_int(test_list1, 2, &func))
		printf("ok 2-2\n");

	dll_c_push_link(link3, test_list1);
	if (dll_l_iter_int(test_list1, 1, &func))
		printf("ok 3-1 ");
	if (dll_l_iter_int(test_list1, 2, &func))
		printf("ok 3-2 ");
	if (dll_l_iter_int(test_list1, 3, &func))
		printf("ok 3-3\n");

	if (!dll_l_iter_int(test_list1, 4, &func))
		printf("ok 4\n");

//	destroy_dll_c(&test_list1);
	destroy_dll_c(&test_list2);
	printf("----------------------- \n");
}

void all_test_dll_c()
{
	test__1_();
	test__2_();
	test__3_();
	test__4_();
	test__5_();
	test__6_();
	test__7_();
	test__8_();
	test__9_();
	test__10_();
	test__11_();
}

//int main()
//{
//	all_test_dll_c();
//	return (0);
//}
