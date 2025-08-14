/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:06 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/14 17:24:03 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_infile(char **argv, t_file_fd *file_fd);
static int	parsing_infile(char **argv, t_file_fd *file_fd);
static int	parsing_outfile(char **argv, t_file_fd *file_fd, int i);
static int	parsing_command_line(int argc, char **argv,
				t_super_list **super_list);

int	parsing_argument(int argc, char **argv, t_file_fd *file_fd,
		t_super_list **super_list)
{
	if (argc < 5)
	{
		print_error("insufficient number of argument");
		return (1);
	}
	if (parsing_infile(argv, file_fd))
		return (1);
	if (parsing_command_line(argc, argv, super_list))
		return (1);
	if (parsing_outfile(argv, file_fd, argc - 1))
		return (1);
	return (0);
}

static int	get_infile(char **argv, t_file_fd *file_fd)
{
	if (access(argv[1], F_OK) == -1)
    {
        print_error("input file doesn't exist");
        return (1);
    }
	file_fd->fdin = open(argv[1], O_RDONLY);
	if (file_fd->fdin == -1)
	{
		print_error("failure openning infile");
        return (1);
	}
	return (0);
}

static int	parsing_infile(char **argv, t_file_fd *file_fd)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		return (here_doc(file_fd));
	else	
		return (get_infile(argv, file_fd));
}

static int	parsing_outfile(char **argv, t_file_fd *file_fd, int i)
{
	file_fd->fdout = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_fd->fdout == -1)
	{
		print_error("failure openning outfile");
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
		if (tab == NULL)
			return (1);
		if (*tab != NULL)
		{
			*super_list = put_super_back(*super_list, tab);
			if (*super_list == NULL)
				return (1);
		}
		clear_tab(tab);
		i++;
	}
	return (0);
}
