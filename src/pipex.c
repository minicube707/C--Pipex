/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/14 16:41:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
    t_super_list	*super_list;
	t_stack_string	*stack_env;
	t_file_fd		file_fd;

    super_list = NULL;
    stack_env = NULL;
    
    /*Parsing Environnement*/
	stack_env = new_stack();
	if (parsing_environnement(&stack_env, envp, "PATH="))
	{
		clear_stack(stack_env);
		return (-1);
	}

    /*Parsing Argument*/
    super_list = new_super_list();
	if (parsing_argument(argc, argv, &file_fd, &super_list))
	{
        clear_stack(stack_env);
		return (-1);
	}
	
    if (parsing_command(&stack_env, &super_list))
		return (-1);
    

    execute_all(&super_list, envp, &file_fd);
    clear_super_list(super_list);
    clear_stack(stack_env);
	return (0);
}
