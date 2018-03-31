#include "../sources/include/sll_header.h"

t_sll list_test;

void static init()
{
	list_test = new_sll();
}

void static destroy()
{
	destroy_sll(&list_test);
}

static void test__1_() // check si destruct et construct work
{
	init();
	destroy();
}

static void test__2_() // check si je destoye bien l'objet
{
	init();
	char *str="test 2 \n check si je destoye bien lobjet";
	(void)str;

	destroy();
}

static void test__3_() // test avec des datas
{
	init();
	char *str="test 3 \n test avec des data`";
	(void)str;
	t_sll_l link1 = new_sll_l("1", 2);
	t_sll_l link2 = new_sll_l("2", 2);;
	t_sll_l link3 = new_sll_l("3", 2);;
	t_sll_l link4 = new_sll_l("4", 2);;

	sll_add(link1, list_test);
	sll_add(link2, list_test);
	sll_add(link3, list_test);
	sll_add(link4, list_test);

	sll_print_str(list_test);

	destroy();
}

void all_test_sll()
{
    test__1_();
    test__2_();
    test__3_();
}

int main()
{
	all_test_sll();
	return (0);
}
