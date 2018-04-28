#ifndef LIBFT_ARGV_H_H
#define LIBFT_ARGV_H_H

#define OPTION "f o p"
#define NO_ARGV "Error no given argv"

/*
**    structure
*/
typedef struct		s_argv
{
	char 			**av;
	char 			**own_splitted_av;
	char 			taken_options[20];
	int 			ac;
	int 			counter;
	int 			counter_osa;

}					*t_argv;

/*
**    construct ================================================================
*/
void  destroy_argv(t_argv *argv);
t_argv new_argv(int ac, char **av);

/*
**    method ===================================================================
*/
int argv_get_next_argv(char **out_argv, t_argv argv);
void argv_get_option(t_argv argv);
void argv_go_prev_argv(t_argv argv);

/*
**    utils ====================================================================
*/
void argv_init_value(char ***av, int *ac, int *counter, t_argv argv);
void argv_error(char *str);
int argv_is_splitted(t_argv argv);
char *get_splitted_next_argv(t_argv argv);
int end_of_split(t_argv argv);
int is_remaining_argv(t_argv argv);
char *get_next_argv(t_argv argv);


/*
**    if av[counter] == "44 55 dd ..." split it in own_splitted_av
**    	add 1 at counter
*/
int is_space_in_argv(t_argv argv);

/*
**    debug ====================================================================
*/


#endif