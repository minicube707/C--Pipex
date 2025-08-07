/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:09:04 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/07 17:44:01 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    copy_pipe(int copy[2], int tab[2])
{
    copy[0] = tab[0];
    copy[1] = tab[1];  
}

int execute_all(t_super_list **super_list, char **envp)
{
    t_super_list    *tmp;
    int nb_cmd;
    int previous_pipe[2];
    pid_t pid;
    
    tmp = *super_list;
    nb_cmd = lenght_super_list(tmp);
    pipe(tmp->mypipe);
    pid = fork();
    if (pid == 0)
    {
        close(tmp->mypipe[0]);
        dup2(tmp->mypipe[1], STDOUT_FILENO);
        close(tmp->mypipe[1]);
        execve(tmp->tab_string[0], tmp->tab_string, envp);
        ft_putstr_fd("error", 1);
        exit(-1);
        
    }
    /*Close les pipes precedent*/
    close(tmp->mypipe[1]);
    
    /*New pipe*/
    copy_pipe(previous_pipe, tmp->mypipe);
    tmp = tmp->next;
    pipe(tmp->mypipe);
    pid = fork();
    if (pid == 0)
    {
        dup2(previous_pipe[0], STDIN_FILENO);
        close(previous_pipe[0]);
        dup2(tmp->mypipe[1], STDOUT_FILENO);
        close(tmp->mypipe[1]);
        execve(tmp->tab_string[0], tmp->tab_string, envp);
        ft_putstr_fd("error", 1);
        exit(-1);
        
    }
    /*Close les pipes precedent*/
    close(previous_pipe[0]);
    close(tmp->mypipe[1]);
    
    /*New pipe*/
    copy_pipe(previous_pipe, tmp->mypipe);
    tmp = tmp->next;
    pipe(tmp->mypipe);
   
    pid = fork();
    if (pid == 0)
    {
        dup2(previous_pipe[0], STDIN_FILENO);
        close(previous_pipe[0]);
        close(tmp->mypipe[1]);
        execve(tmp->tab_string[0], tmp->tab_string, envp);
        ft_putstr_fd("error", 1);
        exit(-1);
    }
    
    /*Close les pipes precedent*/
    close(previous_pipe[0]);
    close(tmp->mypipe[1]);
    
    waitpid(pid, NULL, 0);
    return 0;
}
