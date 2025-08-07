/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:09:04 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/07 16:57:24 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int execute_all(t_super_list **super_list, char **envp)
{
    t_super_list    *tmp;
    int nb_cmd;
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
        
    }
    
    /*
    i = 1;
    tmp = tmp->next;
    while (i < nb_cmd - 2)
    {
        pipe(my_pipe[i]);
        pid[i] = fork();
        if (pid[1] == 0)
        {
            close_all_pipe((int **) my_pipe, i-1);
            execute_command(tmp->tab_string, envp, my_pipe[i][0], my_pipe[i+1][1]);
        }
        i++;
        tmp = tmp->next;
    }
    */
   
    close(tmp->mypipe[1]);
    
    pid = fork();
    if (pid == 0)
    {
        dup2(tmp->mypipe[0], STDIN_FILENO);
        close(tmp->mypipe[0]);
        close(tmp->mypipe[1]);
        tmp = tmp->next;
        execve(tmp->tab_string[0], tmp->tab_string, envp);
    }
    
    close(tmp->mypipe[0]);
    waitpid(pid, NULL, 0);
    return 0;
}
