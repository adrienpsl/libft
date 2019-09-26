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

#ifndef FT_ERRNO_H
#define FT_ERRNO_H

# include "ft_printf.h"

# include "errno.h"

# define FT_ERRNO_MAX 107

int ft_errno_set(int errnum, int ret);
int ft_errno_get(void);

void ft_perror(char *string);
char *ft_strerror(int errnum);

typedef struct s_errno
{
	char *errstr;
	int errnum;
	int align;
} t_errno;

static t_errno g_errno_errs[FT_ERRNO_MAX + 1] = {
	{ "Error not exist",                                 0,   0 },
	{ "Operation not permitted",                         1,   0 },
	{ "No such file or directory",                       2,   0 },
	{ "No such process",                                 3,   0 },
	{ "Interrupted system call",                         4,   0 },
	{ "Input/output error",                              5,   0 },
	{ "Device not configured",                           6,   0 },
	{ "Argument list too long",                          7,   0 },
	{ "Exec format error",                               8,   0 },
	{ "Bad file descriptor",                             9,   0 },
	{ "No child processes",                              10,  0 },
	{ "Resource deadlock avoided",                       11,  0 },
	{ "Cannot allocate memory",                          12,  0 },
	{ "Permission denied",                               13,  0 },
	{ "Bad address",                                     14,  0 },
	{ "Block device required",                           15,  0 },
	{ "Device / Resource busy",                          16,  0 },
	{ "File exists",                                     17,  0 },
	{ "Cross-device link",                               18,  0 },
	{ "Operation not supported by device",               19,  0 },
	{ "Not a directory",                                 20,  0 },
	{ "Is a directory",                                  21,  0 },
	{ "Invalid argument",                                22,  0 },
	{ "Too many open files in system",                   23,  0 },
	{ "Too many open files",                             24,  0 },
	{ "Inappropriate ioctl for device",                  25,  0 },
	{ "Text file busy",                                  26,  0 },
	{ "File too large",                                  27,  0 },
	{ "No space left on device",                         28,  0 },
	{ "Illegal seek",                                    29,  0 },
	{ "Read-only file system",                           30,  0 },
	{ "Too many links",                                  31,  0 },
	{ "Broken pipe",                                     32,  0 },
	{ "Numerical argument out of domain",                33,  0 },
	{ "Result too large",                                34,  0 },
	{ "Resource temporarily unavailable",                35,  0 },
	{ "Operation now in progress",                       36,  0 },
	{ "Operation already in progress",                   37,  0 },
	{ "Socket operation on non-socket",                  38,  0 },
	{ "Destination address required",                    39,  0 },
	{ "Message too long",                                40,  0 },
	{ "Protocol wrong type for socket",                  41,  0 },
	{ "Protocol not available",                          42,  0 },
	{ "Protocol not supported",                          43,  0 },
	{ "Socket type not supported",                       44,  0 },
	{ "Operation not supported on socket",               45,  0 },
	{ "Protocol family not supported",                   46,  0 },
	{ "Address family not supported by protocol family", 47,  0 },
	{ "Address already in use",                          48,  0 },
	{ "Can't assign requested address",                  49,  0 },
	{ "Network is down",                                 50,  0 },
	{ "Network is unreachable",                          51,  0 },
	{ "Network dropped connection on reset",             52,  0 },
	{ "Software caused connection abort",                53,  0 },
	{ "Connection reset by peer",                        54,  0 },
	{ "No buffer space available",                       55,  0 },
	{ "Socket is already connected",                     56,  0 },
	{ "Socket is not connected",                         57,  0 },
	{ "Can't send after socket shutdown",                58,  0 },
	{ "Too many references: can't splice",               59,  0 },
	{ "Operation timed out",                             60,  0 },
	{ "Connection refused",                              61,  0 },
	{ "Too many levels of symbolic links",               62,  0 },
	{ "File name too long",                              63,  0 },
	{ "Host is down",                                    64,  0 },
	{ "No route to host",                                65,  0 },
	{ "Directory not empty",                             66,  0 },
	{ "Too many processes",                              67,  0 },
	{ "Too many users",                                  68,  0 },
	{ "Disc quota exceeded",                             69,  0 },
	{ "Stale NFS file handle",                           70,  0 },
	{ "Too many levels of remote in path",               71,  0 },
	{ "RPC struct is bad",                               72,  0 },
	{ "RPC version wrong",                               73,  0 },
	{ "RPC prog. not avail",                             74,  0 },
	{ "Program version wrong",                           75,  0 },
	{ "Bad procedure for program",                       76,  0 },
	{ "No locks available",                              77,  0 },
	{ "Function not implemented",                        78,  0 },
	{ "Inappropriate file type or format",               79,  0 },
	{ "Authentication error",                            80,  0 },
	{ "Need authenticator",                              81,  0 },
	{ "Device power is off",                             82,  0 },
	{ "Device error, e.g. paper out",                    83,  0 },
	{ "Value too large to be stored in data type",       84,  0 },
	{ "Bad executable",                                  85,  0 },
	{ "Bad CPU type in executable",                      86,  0 },
	{ "Shared library version mismatch",                 87,  0 },
	{ "Malformed Macho file",                            88,  0 },
	{ "Operation canceled",                              89,  0 },
	{ "Identifier removed",                              90,  0 },
	{ "No message of desired type",                      91,  0 },
	{ "Illegal byte sequence",                           92,  0 },
	{ "Attribute not found",                             93,  0 },
	{ "Bad message",                                     94,  0 },
	{ "Reserved",                                        95,  0 },
	{ "No message available on STREAM",                  96,  0 },
	{ "Reserved",                                        97,  0 },
	{ "No STREAM resources",                             98,  0 },
	{ "Not a STREAM",                                    99,  0 },
	{ "Protocol error",                                  100, 0 },
	{ "STREAM ioctl timeout",                            101, 0 },
	{ "Operation not supported on socket",               102, 0 },
	{ "No such policy registered",                       103, 0 },
	{ "State not recoverable",                           104, 0 },
	{ "Previous owner died",                             105, 0 },
	{ "Interface output queue is full",                  106, 0 }
};

#endif
