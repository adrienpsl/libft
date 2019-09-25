
#ifndef FT_LOG_H
#define FT_LOG_H

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
