/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/16 13:46:19 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clear(t_super_list *super_list, t_stack_string *stack_env)
{
	clear_super_list(super_list);
	clear_stack(stack_env);
}

static int	parsing1(t_stack_string **stack_env, char **envp)
{
	if (parsing_environnement(stack_env, envp, "PATH="))
	{
		clear_stack(*stack_env);
		return (-1);
	}
	return (0);
}

static int	parsing3(t_stack_string **stack_env, t_super_list **super_list,
		t_file_fd *file_fd)
{
	if (parsing_command(stack_env, super_list, file_fd))
	{
		close(file_fd->fdin);
		close(file_fd->fdout);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_super_list	*super_list;
	t_stack_string	*stack_env;
	t_file_fd		file_fd;

	super_list = NULL;
	stack_env = NULL;
	stack_env = new_stack();
	if (parsing1(&stack_env, envp))
		return (-1);
	super_list = new_super_list();
	if (parsing_argument(argc, argv, &file_fd, &super_list))
	{
		clear(super_list, stack_env);
		return (-1);
	}
	if (parsing3(&stack_env, &super_list, &file_fd))
		return (-1);
	execute_all(&super_list, envp);
	clear(super_list, stack_env);
	return (0);
}
