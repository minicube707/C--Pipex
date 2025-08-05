/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/05 03:26:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
    t_super_list	*super_list;
	t_stack_string	*stack_env;
	t_stack_string	*stack_cmd;
	t_file			file;

    super_list = NULL;
    stack_env = NULL;
    stack_cmd = NULL;
    file.infile = NULL;
    file.outfile = NULL;
    
    /*Parsing Environnement*/
	stack_env = new_stack();
	if (parsing_environnement(&stack_env, envp, "PATH="))
	{
		free_all(stack_env, NULL, NULL);
		return (-1);
	}

    /*Parsing Argument*/
	stack_cmd = new_stack();
	if (parsing_argument(argc, argv, &file, &stack_cmd))
	{
        free_all(stack_env, stack_cmd, &file);
		return (-1);
	}
    



    
    super_list = new_super_list();
    if (parsing_command(&stack_cmd, &super_list))
	{
        free_all(stack_env, NULL, &file);
		return (-1);
	}
    print_super_list(super_list);
    clear_super_list(super_list);

	while (!is_empty_stack(stack_env))
	{
		printf("%s \n", stack_env->string);
		stack_env = pop_stack(stack_env);
	}
    
	printf("INFILE %s \n", file.infile);
	printf("OUTFILE %s \n", file.outfile);
	free(file.infile);
	free(file.outfile);
    
	while (!is_empty_stack(stack_cmd))
	{
		printf("%s \n", stack_cmd->string);
		stack_cmd = pop_stack(stack_cmd);
	}
	return (0);
}
