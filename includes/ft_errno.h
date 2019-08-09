" ************************************************************************** "
"                                                                            "
"                                                        :::      ::::::::   "
"   ft_atoi.c                                          :+:      :+:    :+:   "
"                                                    +:+ +:+         +:+     "
"   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        "
"                                                +#+#+#+#+#+   +#+           "
"   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             "
"   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       "
"                                                                            "
" ************************************************************************** "

#ifndef FT_ERRNO_H
#define FT_ERRNO_H

# include "errno.h"

int g_errno;

void ft_errno_set(int nb_error);
void ft_perror(char *string);
void ft_strerror(int errnum);

typedef struct s_errno
{
	int errnum;
	char *errstr;
} t_errno;

t_errno g_errno_errs[103] = {
{ 1,   " Operation not permitted" },
{ 2,   " No such file or directory" },
{ 3,   " No such process" },
{ 4,   " Interrupted system call" },
{ 5,   " Input/output error" },
{ 6,   " Device not configured" },
{ 7,   " Argument list too long" },
{ 8,   " Exec format error" },
{ 9,   " Bad file descriptor" },
{ 10,  " No child processes" },
{ 11,  " Resource deadlock avoided" },
{ 12,  " Cannot allocate memory" },
{ 13,  " Permission denied" },
{ 14,  " Bad address" },
{ 16,  " Device / Resource busy" },
{ 17,  " File exists" },
{ 18,  " Cross-device link" },
{ 19,  " Operation not supported by device" },
{ 20,  " Not a directory" },
{ 21,  " Is a directory" },
{ 22,  " Invalid argument" },
{ 23,  " Too many open files in system" },
{ 24,  " Too many open files" },
{ 25,  " Inappropriate ioctl for device" },
{ 26,  " Text file busy" },
{ 27,  " File too large" },
{ 28,  " No space left on device" },
{ 29,  " Illegal seek" },
{ 30,  " Read-only file system" },
{ 31,  " Too many links" },
{ 32,  " Broken pipe" },
{ 33,  " Numerical argument out of domain" },
{ 34,  " Result too large" },
{ 35,  " Resource temporarily unavailable" },
{ 36,  " Operation now in progress" },
{ 37,  " Operation already in progress" },
{ 38,  " Socket operation on non-socket" },
{ 39,  " Destination address required" },
{ 40,  " Message too long" },
{ 41,  " Protocol wrong type for socket" },
{ 42,  " Protocol not available" },
{ 43,  " Protocol not supported" },
{ 47,  " Address family not supported by protocol family" },
{ 48,  " Address already in use" },
{ 49,  " Can't assign requested address" },
{ 50,  " Network is down" },
{ 51,  " Network is unreachable" },
{ 52,  " Network dropped connection on reset" },
{ 53,  " Software caused connection abort" },
{ 54,  " Connection reset by peer" },
{ 55,  " No buffer space available" },
{ 56,  " Socket is already connected" },
{ 57,  " Socket is not connected" },
{ 60,  " Operation timed out" },
{ 61,  " Connection refused" },
{ 62,  " Too many levels of symbolic links" },
{ 63,  " File name too long" },
{ 69,  " Disc quota exceeded" },
{ 70,  " Stale NFS file handle" },
{ 77,  " No locks available" },
{ 78,  " Function not implemented" },
{ 84,  " Value too large to be stored in data type" },
{ 89,  " Operation canceled" },
{ 90,  " Identifier removed" },
{ 91,  " No message of desired type" },
{ 92,  " Illegal byte sequence" },
{ 94,  " Bad message" },
{ 95,  " Reserved" },
{ 96,  " No message available on STREAM" },
{ 97,  " Reserved" },
{ 98,  " No STREAM resources" },
{ 99,  " Not a STREAM" },
{ 100, " Protocol error" },
{ 101, " STREAM ioctl timeout" } };



