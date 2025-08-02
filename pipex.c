/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 23:31:15 by florent           #+#    #+#             */
/*   Updated: 2025/08/02 23:31:19 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    t_stack_string *stack;
    int error;

    (void ) argc;
    (void ) argv;
    stack = new_stack();
    error = ft_getenv(&stack, envp, "PATH=");
    if (error)
    {
        clear_stack(stack);
        return (-1);
    }
    while (!is_empty_stack(stack))
    {
        printf("%s \n", stack->string);
        stack = pop_stack(stack);
    }
    return (0);
}
