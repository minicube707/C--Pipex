/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:23:06 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/16 13:46:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_infile(char **argv, t_file_fd *file_fd, int *start);
static int	parsing_infile(char **argv, t_file_fd *file_fd, int *start);
static int	parsing_outfile(char **argv, t_file_fd *file_fd, int i, int start);
static int	parsing_command_line(int argc, char **argv,
				t_super_list **super_list, int start);

int	parsing_argument(int argc, char **argv, t_file_fd *file_fd,
		t_super_list **super_list)
{
	int	start;

	if ((ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0 && argc < 6)
		|| argc < 5)
	{
		print_error("insufficient number of argument");
		return (1);
	}
	if (parsing_infile(argv, file_fd, &start))
		return (1);
	if (parsing_command_line(argc, argv, super_list, start))
		return (1);
	if (parsing_outfile(argv, file_fd, argc - 1, start))
		return (1);
	return (0);
}

static int	get_infile(char **argv, t_file_fd *file_fd, int *start)
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
	*start = 2;
	return (0);
}

static int	parsing_infile(char **argv, t_file_fd *file_fd, int *start)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		return (here_doc(file_fd, argv[2], start));
	else
		return (get_infile(argv, file_fd, start));
}

static int	parsing_outfile(char **argv, t_file_fd *file_fd, int i, int start)
{
	int	open_flags;

	if (start == 2)
		open_flags = O_CREAT | O_WRONLY | O_TRUNC;
	else
		open_flags = O_CREAT | O_WRONLY | O_APPEND;
	file_fd->fdout = open(argv[i], open_flags, 0644);
	if (file_fd->fdout == -1)
	{
		print_error("failure openning outfile");
		close(file_fd->fdin);
		return (1);
	}
	return (0);
}

static int	parsing_command_line(int argc, char **argv,
		t_super_list **super_list, int start)
{
	t_stack_string	*stack;
	char			**tab;
	int				i;

	tab = NULL;
	i = start;
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
