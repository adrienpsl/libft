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

#include "libft.h"

void test_ftsystm_check_exe(void)
{
	// with the rigth :
	system("touch toto; chmod 700 toto");
	if (ftsystm_check_exe("./toto") != OK)
	    log_test(1);
	system("touch toto; chmod 644 toto");
	if (ftsystm_check_exe("./toto") != -1)
		log_test(2);
	system("rm toto");

}
