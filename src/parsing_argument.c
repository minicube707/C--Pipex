/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:06 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/11 19:58:22 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	parsing_infile(char **argv, t_file *file);
static int	parsing_outfile(char **argv, t_file *file, int i);
static int	parsing_command_line(int argc, char **argv,
				t_super_list **super_list);

int	parsing_argument(int argc, char **argv, t_file *file,
		t_super_list **super_list)
{
	if (argc < 5)
	{
		print_error("insufficient number of elements");
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
	if (parsing_outfile(argv, file, argc - 1))
	{
		free(file->infile);
		file->infile = NULL;
		return (1);
	}
	return (0);
}

static int	parsing_infile(char **argv, t_file *file)
{
	file->infile = ft_strdup(argv[1]);
	if (file->infile == NULL)
	{
		print_error("Problem allocation dynamique with dup in stack");
		return (1);
	}
	return (0);
}

static int	parsing_outfile(char **argv, t_file *file, int i)
{
	file->outfile = ft_strdup(argv[i]);
	if (file->outfile == NULL)
	{
		print_error("Problem allocation dynamique with dup in stack");
		free(file->infile);
		return (1);
	}
	return (0);
}

static int	parsing_command_line(int argc, char **argv,
		t_super_list **super_list)
{
	t_stack_string	*stack;
	char			**tab;
	int				i;

	tab = NULL;
	i = 2;
	while (i < argc - 1)
	{
		if (check_nb_quote(argv[i], *super_list))
			return (1);
		stack = split_commmand(argv[i]);
		tab = stack_to_tab(stack);
		if (*tab != NULL)
		{
			*super_list = put_super_back(*super_list, tab);
			if (*super_list == NULL)
			{
				clear_tab(tab);
				return (1);
			}
		}
		clear_tab(tab);
		i++;
	}
	return (0);
}
