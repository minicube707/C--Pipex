/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:06 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/08 15:07:42 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int parsing_infile(char **argv, t_file *file);
static int parsing_outfile(char **argv, t_file *file, int i);
static int parsing_command_line(int argc, char **argv, t_super_list **super_list);

int parsing_argument(int argc, char **argv, t_file *file, t_super_list **super_list)
{
    
    if (argc < 3)
    {
        ft_putstr_fd("Error: insufficient number of elements\n", 1); 
        return (1);
    }
    if (parsing_infile(argv, file))
        return (1);
    if (parsing_command_line(argc, argv, super_list))
    {
        free(file->infile);
        file->infile = NULL;
        return (1);
    }
    if (parsing_outfile(argv, file, argc -1))
    {
        free(file->infile);
        file->infile = NULL;
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

static int parsing_command_line(int argc, char **argv, t_super_list **super_list)
{   
    char    **tab;
    int i;

    tab = NULL;
    i = 2;
    while (i < argc - 1)
    {
        if (check_nb_quote(argv[i], *super_list))
            return (1);
        split_commmand(argv[i]);
        tab = ft_split(argv[i], ' ');
        *super_list = put_super_back(*super_list, tab);
        if (*super_list == NULL)
        {
            clear_tab(tab);
            return (1);
        }
        clear_tab(tab);
        i++;
    }
    return (0);
}
