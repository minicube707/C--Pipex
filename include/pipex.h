
#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_bool
{
	false,
	true
}							t_bool;

typedef struct s_stack_string
{
	char					*string;
	struct s_stack_string	*next;
}							t_stack_string;

typedef struct s_file
{
	char					*infile;
	char					*outfile;
}							t_file;

typedef struct s_two_string
{
	char					*string1;
	char					*string2;
}							t_two_string;

typedef struct s_super_list
{
	char					**tab_string;
	int						mypipe[2];
	struct s_super_list		*next;

}							t_super_list;

/*Stack*/
t_stack_string				*new_stack(void);
t_bool						is_empty_stack(t_stack_string *st);
t_stack_string				*push_stack(t_stack_string *st, char *string);
t_stack_string				*clear_stack(t_stack_string *st);
t_stack_string				*pop_stack(t_stack_string *st);
t_stack_string				*inversion_stack(t_stack_string *st);
void						print_stack(t_stack_string *st);
t_stack_string				*reverse_stack(t_stack_string *st);
t_stack_string				*copy_stack(t_stack_string *st);

/*Super List*/
t_super_list				*new_super_list(void);
t_bool						is_empty_super_list(t_super_list *li);
int							lenght_super_list(t_super_list *li);
void						print_super_list(t_super_list *li);
t_super_list				*put_super_back(t_super_list *su, char **tab);
t_super_list				*pop_super_front(t_super_list *li);
t_super_list				*clear_super_list(t_super_list *li);

/*Tab Utils*/
char						**copy_tab(char **tab);
void						clear_tab(char **tab);
void						print_tab(char **tab);
char						**stack_to_tab(t_stack_string *stack);

/*Parsing environnement*/
int							parsing_environnement(t_stack_string **stack,
								char **envp, char *var);

/*Parsing Argument*/
int							parsing_argument(int argc, char **argv,
								t_file *file, t_super_list **super_list);

/*Parsing Command*/
int							parsing_command(t_stack_string **stack_env,
								t_super_list **super_list);

/*Free file*/
void						free_file(t_file *file);

/*Check Command*/
int							check_command(t_stack_string **stack, char **tab);

/*Execute*/
int							execute_all(t_super_list **super_list, char **envp);

/*Check_Nb_Quote*/
int							count_nb_quote(char *string);
int							check_nb_quote(char *tab, t_super_list *super_list);

/*Split Command*/
t_stack_string				*split_commmand(char *string);
char						*get_before_sep(char *string, char **after,
								int sep);
char						*duplicate_and_push(t_stack_string **stack,
								char *res, char *new_tmp);

#endif