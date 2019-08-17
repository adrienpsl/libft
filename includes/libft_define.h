
#ifndef FT_LIBFT_DEFINE_H
#define FT_LIBFT_DEFINE_H

# define FT_BUFFER_INDEX sizeof(size_t)
# define FT_BUFFER_LIM 10
# define FT_BUFFER_SIZE (FT_BUFFER_LIM + FT_BUFFER_INDEX)

# define FT_TESTING_BUFFER_LIM 10000
# define FT_TESTING_BUFFER_SIZE (FT_TESTING_BUFFER_LIM + FT_BUFFER_INDEX)

# define TRUE 1
# define FALSE 0
# define MEMORY_LACK 100
# define SAME_SIZE 0
# define FREE  1
# define FREE_FIRST  1
# define FREE_SECOND 1 << 1
# define FREE_THIRD  1 << 2
# define NOT_FIND  -1

# define OK 0
# define ERROR 1

# define FT_CMP_STRING 1
# define FT_CMP_INT 2

# define PTR_SIZE sizeof(char*)


#endif
