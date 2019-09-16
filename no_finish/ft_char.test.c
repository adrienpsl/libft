#include <libft.h>

int					test_ft_char()
{
	/*  test char ----------------------------------------------------------- */
	char arr[8] = {'u', 127, 129, -109, '0', '9', 'a', 'Z'};
	//
	int res_ascii[8] = {1, 1, 0, 0, 1, 1, 1, 1};
	//
	int res_digit[8] = {0, 0, 0, 0, 1, 1, 0, 0};
	//
	int res_alpha[8] = {1, 0, 0, 0, 0, 0, 1, 1};
	//
	int res_alpha_digi[8] = {1, 0, 0, 0, 1, 1, 1, 1};


	for (int i = 0; i < 8; ++i)
	{
		if (res_ascii[i] != ft_char_test(arr[i], FT_CHAR_ASCII))
			return 1;
		if (res_digit[i] != ft_char_test(arr[i], FT_CHAR_DIGIT))
			return 1;
		if (res_alpha[i] != ft_char_test(arr[i], FT_CHAR_ALPHA))
			return 1;
		if (res_alpha_digi[i] != ft_char_test(arr[i], FT_CHAR_ALPHA_DIGIT))
			return 1;
	}

	char *capti = "0 9 a z A Z \n \t \232";
	char *capi_upper = "0 9 A Z A Z \n \t \232";
	char *capi_lower = "0 9 a z a z \n \t \232";

	/* capitalise ----------------------------------------------------------- */
	size_t len = strlen(capti);

	for (size_t j = 0; j < len; ++j)
	{
		if (capi_upper[j] != ft_capitalise(capti[j], 1))
			return 1;
		if (capi_lower[j] != ft_capitalise(capti[j], 0))
			return 1;
	}

	return 0;
}
