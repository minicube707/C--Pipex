/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:09:04 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/11 20:02:43 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	manage_pipe(int previous_pipe[2], t_super_list *tmp, char **envp)
{
	dup2(previous_pipe[0], STDIN_FILENO);
	close(previous_pipe[0]);
	dup2(tmp->mypipe[1], STDOUT_FILENO);
	close(tmp->mypipe[1]);
	close(tmp->mypipe[0]);
	execve(tmp->tab_string[0], tmp->tab_string, envp);
	print_error("command failure");
	exit(-1);
}

static t_super_list	*first_cmd(t_super_list *tmp, char **envp)
{
	pid_t	pid;

	if (pipe(tmp->mypipe) == -1)
	{
		print_error("failure creation of pipe");
		clear_tab(envp);
		return (NULL);
	}
	pid = fork();
	if (pid == 0)
	{
		close(tmp->mypipe[0]);
		dup2(tmp->mypipe[1], STDOUT_FILENO);
		close(tmp->mypipe[1]);
		execve(tmp->tab_string[0], tmp->tab_string, envp);
		print_error("command failure");
		exit(-1);
	}
	close(tmp->mypipe[1]);
	return (tmp);
}

static t_super_list	*last_cmd(t_super_list *tmp, char **envp,
		int previous_pipe[2], pid_t *last_pid)
{
	pid_t	pid;

	copy_pipe(previous_pipe, tmp->mypipe);
	tmp = tmp->next;
	if (pipe(tmp->mypipe) == -1)
	{
		clear_tab(envp);
		print_error("failure creation of pipe");
		return (NULL);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(previous_pipe[0], STDIN_FILENO);
		close(previous_pipe[0]);
		close(tmp->mypipe[1]);
		close(tmp->mypipe[0]);
		execve(tmp->tab_string[0], tmp->tab_string, envp);
		print_error("command failure");
		exit(-1);
	}
	*last_pid = pid;
	return (tmp);
}

static t_super_list	*mid_cmd(t_super_list *tmp, char **envp,
		int previous_pipe[2], int nb_cmd)
{
	pid_t	pid;

	while (nb_cmd--)
	{
		copy_pipe(previous_pipe, tmp->mypipe);
		tmp = tmp->next;
		if (pipe(tmp->mypipe) == -1)
		{
			clear_tab(envp);
			print_error("failure creation of pipe");
			return (NULL);
		}
		pid = fork();
		if (pid == 0)
			manage_pipe(previous_pipe, tmp, envp);
		close(previous_pipe[0]);
		close(tmp->mypipe[1]);
	}
	return (tmp);
}

int	execute_all(t_super_list **super_list, char **envp)
{
	t_super_list	*tmp;
	int				nb_cmd;
	int				previous_pipe[2];
	pid_t			pid;

	tmp = *super_list;
	nb_cmd = lenght_super_list(tmp) - 2;
	tmp = first_cmd(tmp, envp);
	tmp = mid_cmd(tmp, envp, previous_pipe, nb_cmd);
	tmp = last_cmd(tmp, envp, previous_pipe, &pid);
	close(previous_pipe[0]);
	close(tmp->mypipe[1]);
	close(tmp->mypipe[0]);
	waitpid(pid, NULL, 0);
	return (0);
}
