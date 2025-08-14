/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:22:05 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/14 18:11:05 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int here_doc(t_file_fd *file_fd)
{
    char    *intput;
    char    *name_file;
    int true;
    
    name_file = "here_doc";
    true = 1;
    file_fd->fdin = open(name_file,  O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0600);
    if (file_fd->fdin == -1)
	{
		print_error("failure creation here_doc file");
        return (1);
	}
    if (unlink(name_file))
    {
        print_error("failure unlink here_doc");
        close(file_fd->fdin);
        return (1);
    }
    while (true)
    {
        intput = get_next_line(STDIN_FILENO);
    }
    return (0);
}