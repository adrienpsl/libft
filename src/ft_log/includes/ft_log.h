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

#ifndef FT_LOG_H
# define FT_LOG_H

# define F __FILE__
# define L __LINE__

# include <errno.h>

extern int	g_log;
int			g_log;
enum		e_log_level
{
	QUIET,
	INFO,
	TRACE,
};

int			ftlog__null(char *file, int line);
int			ftlog__message(char *file, int line, char *message, int error_code);

#endif
