/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:22:05 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/15 23:56:47 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	write_content(t_file_fd *file_fd, char *input)
{
	if (write(file_fd->fdin, input, ft_strlen(input)) == -1)
	{
		free(input);
		print_error("failure writing in here_doc");
		close(file_fd->fdin);
		return (1);
	}
	return (0);
}

static int	write_here_doc(t_file_fd *file_fd)
{
	if (write(1, "here_doc> ", ft_strlen("here_doc> ")) == -1)
	{
		print_error("failure writing in here_doc");
		close(file_fd->fdin);
		return (1);
	}
	return (0);
}

static int	here_doc_loop(t_file_fd *file_fd, char *limiter, t_bool *true)
{
	char	*input;
	int		condition1;
	int		condition2;

	if (write_here_doc(file_fd))
		return (1);
	input = get_next_line(STDIN_FILENO);
	if (input == NULL)
		return (1);
	condition1 = ft_strncmp(input, limiter, ft_strlen(input) - 1) == 0;
	condition2 = ft_strlen(input) - 1 == ft_strlen(limiter);
	if (condition1 && condition2)
		*true = 0;
	else
	{
		if (write_content(file_fd, input))
			return (1);
	}
	free(input);
	return (0);
}

int	here_doc(t_file_fd *file_fd, char *limiter, int *start)
{
	char		*name_file;
	t_bool		true;

	name_file = ".here_doc";
	true = 1;
	file_fd->fdin = open(name_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file_fd->fdin == -1)
	{
		print_error("failure creation here_doc file");
		return (1);
	}
	while (true)
		here_doc_loop(file_fd, limiter, &true);
	*start = 3;
	close(file_fd->fdin);
	file_fd->fdin = open(name_file, 0644);
	if (unlink(name_file))
	{
		print_error("failure unlink here_doc");
		close(file_fd->fdin);
		return (1);
	}
	return (0);
}
