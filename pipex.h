
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef enum e_bool
{
	false,
	true
}   t_bool;


typedef struct s_stack_string
{
	char    *string;
	struct s_stack_string	*next;
}					t_stack_string;

/*Stack*/
t_stack_string	*new_stack(void);
t_bool	is_empty_stack(t_stack_string *st);
t_stack_string	*push_stack(t_stack_string *st, char *string);
t_stack_string	*clear_stack(t_stack_string *st);
t_stack_string	*pop_stack(t_stack_string *st);

/*Ft_multijion*/
char	*ft_strmultijoin(char **s2);

/*Ft_getenv*/
int ft_getenv(t_stack_string **stack, char **envp, char *var);
char **fill_tab(char **tab, char *string);
char **create_tab(char **tab_env, char **tab, char *res);
void manage_free(char **tab_env, char **tab, char *res);

#endif