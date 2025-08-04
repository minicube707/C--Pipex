/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/04 23:11:08 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_stack_string	*stack_env;
	t_stack_string	*stack_cmd;
	t_file			file;

    /*Parsing Environnement*/
	stack_env = new_stack();
	if (ft_getenv(&stack_env, envp, "PATH="))
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
    
    /*Check Infile*/
    if (access(file.infile, F_OK))
    {
        ft_putstr_fd("Error: the file doesnt exit\n", 1);
        free_all(stack_env, stack_cmd, &file);
		return (-1);
    }
    ft_putstr_fd("File exist\n", 1);
    
    
    
    

    
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
