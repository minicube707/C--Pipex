/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:37:38 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/05 02:56:36 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parsing_command(t_stack_string **stack, t_super_list **super_list)
{   
    char **tab;
    char *string;

    while (!is_empty_stack(*stack))
    {
        string = (*stack)->string;
        tab = ft_split(string, ' ');
        *super_list = put_super_back(*super_list, tab);
        clear_tab(tab);
        *stack = pop_stack(*stack);
    }
    return (0);
}
