/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:06 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 22:25:03 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int parsing_infile(char **argv, t_file *file);
static int parsing_outfile(char **argv, t_file *file, int i);
static int parsing_command(int argc, char **argv, t_stack_string **stack);

int parsing_argument(int argc, char **argv, t_file *file, t_stack_string **stack)
{
    
    if (argc < 3)
    {
        ft_putstr_fd("Error: insufficient number of elements", 1); 
        return (1);
    }
    if (parsing_infile(argv, file))
        return (1);
    if (parsing_command(argc, argv, stack))
    {
        free(file->infile);
        return (1);
    }
    if (parsing_outfile(argv, file, argc -1))
    {
        free(file->infile);
        return (1);
    }   
    return (0);
}

static int parsing_infile(char **argv, t_file *file)
{
    file->infile = ft_strdup(argv[1]);
    if (file->infile == NULL)
    {
        ft_putstr_fd("Probleme allocation dynamique with dup in stack\n", 1);
        return (1);
    }
    return (0);
}

static int parsing_outfile(char **argv, t_file *file, int i)
{
    file->outfile = ft_strdup(argv[i]);
    if (file->outfile == NULL)
    {
        ft_putstr_fd("Probleme allocation dynamique with dup in stack\n", 1);
        free(file->infile);
        return (1); 
    } 
    return (0);
}

static int parsing_command(int argc, char **argv, t_stack_string **stack)
{   
    int i;

    i = 2;
    while (i < argc - 1)
    {
        *stack = push_stack(*stack, argv[i]);
        if (*stack == NULL)
            return (1);
        i++;
    }
    *stack = inversion_stack(*stack);
    if (*stack == NULL)
        return (1);
    return (0);
}
