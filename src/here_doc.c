/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:22:05 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/15 19:32:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int here_doc(t_file_fd *file_fd, char *limiter, int *start)
{
    char    *intput;
    char    *name_file;
    t_bool  true;
    
    name_file = ".here_doc";
    true = 1;
    file_fd->fdin = open(name_file,  O_CREAT | O_RDWR | O_TRUNC, 0600);
    if (file_fd->fdin == -1)
	{
		print_error("failure creation here_doc file");
        return (1);
	}
    while (true)
    {
        write(1, "heredoc> ", ft_strlen("heredoc> "));
        intput = get_next_line(STDIN_FILENO);
        if (intput == NULL)
            return (1); 
        if (ft_strncmp(intput, limiter, ft_strlen(intput) - 1) == 0 && ft_strlen(intput) - 1 == ft_strlen(limiter)) 
            true = 0;
        else
            write(file_fd->fdin, intput, ft_strlen(intput));
        free(intput);
    }
    *start = 3;
    close(file_fd->fdin);
    file_fd->fdin = open(name_file, 0600);
    if (unlink(name_file))
    {
        print_error("failure unlink here_doc");
        close(file_fd->fdin); return (1);
    }
    return (0);
}
