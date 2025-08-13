/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:29:05 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/13 17:28:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_file(t_file *file)
{ 
    int fd;
    
    printf("ACESS1 %d \n", access(file->infile, F_OK));
    if (access(file->infile, F_OK))
    {
        free_file(file);
        print_error("input file doesn't exist");
        return (1);
    }
    return (0);
}
