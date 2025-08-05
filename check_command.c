/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 07:22:10 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/05 10:24:31 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_command(t_stack_string **stack, char **tab)
{
    t_stack_string *tmp;
    char *join;
    
    tmp = *stack; 
    join = ft_strjoin(tmp->string, tab[0]);
    while (access(join, F_OK) && tmp->next != NULL)
    {   
        free(join);
        tmp = tmp->next;
        join = ft_strjoin(tmp->string, tab[0]);
    }
    if (!access(join, F_OK))
    {
        free(tab[0]);
        tab[0] = join; 
        return (0);
    }
        
    ft_putstr_fd("Error: command doesn't exit\n", 1);
    free(join);
    return (1);
}
