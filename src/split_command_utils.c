/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:35:54 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/13 00:29:16 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_before_sep(char *string, char **after, int sep)
{
	char	*before;
	char	*occ;

	if (string == NULL)
		return (NULL);
	occ = ft_strchr(string, sep);
	before = ft_substr(string, 0, ft_strlen(string) - ft_strlen(occ));
	if (before == NULL)
	{
		*after = NULL;
		return (NULL);
	}
	if (occ == NULL)
	{
		*after = NULL;
		return (before);
	}
	occ++;
	*after = ft_strdup(occ);
	if (*after == NULL)
	{
		free(before);
		return (NULL);
	}
	return (before);
}

char	*duplicate_and_push(t_stack_string **stack, char *res, char *new_tmp)
{
	char	*tmp;

	if (res == NULL)
		return (NULL);
	*stack = push_stack(*stack, res);
	if (*stack == NULL)
		return (NULL);
	tmp = ft_strdup(new_tmp);
	if (tmp == NULL)
	{
		clear_stack(*stack);
		return (NULL);
	}
	return (tmp);
}
