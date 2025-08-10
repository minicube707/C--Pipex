/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 07:22:10 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/10 22:43:50 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_command(t_stack_string **stack, char **tab)
{
    t_stack_string *tmp;
    char *join;
    
    if (**tab == '/')
        return (0);
    tmp = *stack; 
    join = ft_strjoin(tmp->string, *tab);
    while (access(join, F_OK) && tmp->next != NULL)
    {   
        free(join);
        tmp = tmp->next;
        join = ft_strjoin(tmp->string, *tab);
    }
    if (!access(join, F_OK))
    {
        free(tab[0]);
        tab[0] = join; 
        return (0);
    }
    print_error_unknow_cmd(*tab);
    free(join);
    return (1);
}
