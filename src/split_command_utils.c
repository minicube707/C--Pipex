/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:35:54 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/11 16:31:08 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_before_sep(char *string, char **after, int sep)
{
	char	*before;
	char	*occ;

	occ = ft_strchr(string, sep);
	before = ft_substr(string, 0, ft_strlen(string) - ft_strlen(occ));
	if (before == NULL)
		return (NULL);
	if (occ != NULL)
	{
		occ++;
		*after = ft_strdup(occ);
		if (*after == NULL)
			return (NULL);
	}
	else
		*after = NULL;
	return (before);
}

char	*duplicate_and_push(t_stack_string **stack, char *res, char *new_tmp)
{
	char	*tmp;

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
