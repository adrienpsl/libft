
#ifndef FT_LOG_H
#define FT_LOG_H

#define F __FILE__
#define L __LINE__

#include <errno.h>

int g_log;
enum e_log_level {
	QUIET,
	INFO,
	TRACE,
};

int ft_log$null(char *file, int line);
int ft_log$message(char *file, int line, char *message, int error_code);

#endif
