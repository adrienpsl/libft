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

int ft_strsplit_search(char **split, int(*f)(char *, void *), void *param)
{
	int i;

	if (!split || !*split)
		return (-1);
	i = 0;
	while (split[i])
	{
		if (f(split[i], param))
		    return (i);
		i++;
	}
	return (-1);
}

