/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/10 21:42:54 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
    t_super_list	*super_list;
	t_stack_string	*stack_env;
	t_file			file;

    super_list = NULL;
    stack_env = NULL;
    file.infile = NULL;
    file.outfile = NULL;
    
    /*Parsing Environnement*/
	stack_env = new_stack();
	if (parsing_environnement(&stack_env, envp, "PATH="))
	{
		clear_stack(stack_env);
		return (-1);
	}

    /*Parsing Argument*/
    super_list = new_super_list();
	if (parsing_argument(argc, argv, &file, &super_list))
	{
        clear_stack(stack_env);
        free_file(&file);
		return (-1);
	}
	
    if (parsing_command(&stack_env, &super_list))
	{
        free_file(&file);
		return (-1);
	}
    

    execute_all(&super_list, envp);
    clear_super_list(super_list);

    printf("\n");
	printf("INFILE %s \n", file.infile);
	printf("OUTFILE %s \n", file.outfile);
	free_file(&file);
    clear_stack(stack_env);
    
	return (0);
}
