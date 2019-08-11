
#ifndef FT_LOG_H
#define FT_LOG_H

static struct s_ft_log{
	int level;
	int quiet;
} g_log;

static const char *level_names[] = {
"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

static const char *level_colors[] = {
"\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m", "\x1b[35m"
};

#endif
