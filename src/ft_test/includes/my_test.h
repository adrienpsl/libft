/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MY_TEST_H
#define LIBFT_MY_TEST_H

# define log_test(test_nb) \
printf("log : %s:%d: test: %d\n", __FILE__, __LINE__, test_nb);

# define log_test_line(test_nb, line) \
printf("log : %s:%d: test: %d\n", __FILE__, line, test_nb);


#endif //LIBFT_MY_TEST_H
