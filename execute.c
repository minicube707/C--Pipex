/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:09:04 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/05 03:24:21 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void    wait_all_pid(pid_t *pid, int nb_cmd)
{
    int i;
    
    i = 0;
    while (i < nb_cmd)
    {
        waitpid(pid[i], NULL, 0);
        i++;
    }
}
static void    close_all_pipe(int **my_pipe, int nb_cmd)
{
    int i;
    
    i = 0;
    while (i < nb_cmd -1 )
    {
        close(my_pipe[i][1]);
        close(my_pipe[i][0]);
        i++;
    }
}

void    execute_command(char *cmd[], char **envp, int input_fd, int output_fd)
{
    if (input_fd != STDIN_FILENO)
    {
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
    }
    if (output_fd != STDOUT_FILENO)
    {
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);
    }
    execve(cmd[0], cmd, envp);
    perror("execve failed");
    exit(EXIT_FAILURE);
}

int execute_all(t_super_list **super_list, char **envp)
{
    t_super_list    *tmp;
    int my_pipe[256][2];
    int nb_cmd;
    pid_t pid[256];
    int     i;
    
    tmp = *super_list;
    nb_cmd = lenght_super_list(tmp);
    pipe(my_pipe[0]);
    pid[0] = fork();
    if (my_pipe == 0)
    {
        close(my_pipe[0][0]);
        execute_command(tmp->tab_string, envp, STDIN_FILENO, my_pipe[0][1]);
    }
    
    i = 1;
    tmp = tmp->next;
    while (i < nb_cmd - 2)
    {
        pipe(my_pipe[i]);
        pid[i] = fork();
        if (pid[1] == 0)
        {
            close(my_pipe[i][1]);
            close(my_pipe[i][0]);
            execute_command(tmp->tab_string, envp, my_pipe[i][0], my_pipe[i+1][1]);
        }

        /*Close ALl*/
        close_all_pipe(my_pipe, nb_cmd);
        i++;
        tmp = tmp->next;
    }
    pid[i] = fork();
    if (pid[i] == 0)
        execute_command(tmp->tab_string, envp, my_pipe[i][0], STDOUT_FILENO);

    close_all_pipe(my_pipe, nb_cmd);
    wait_all_pid(pid, nb_cmd);
    return 0;
}
