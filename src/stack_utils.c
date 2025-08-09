/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:56:07 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/09 16:04:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_stack_string	*reverse_stack(t_stack_string *st)
{
	t_stack_string	*new_st;
	char			*string;

	new_st = new_stack();
	while (st != NULL)
	{
		string = ft_strdup(st->string);
		st = pop_stack(st);
		new_st = push_stack(new_st, string);
		free(string);
	}
	return (new_st);
}

t_stack_string	*copy_stack(t_stack_string *st)
{
	t_stack_string	*new_st;
	char			*string;

	new_st = new_stack();
	while (st != NULL)
	{
		string = ft_strdup(st->string);
		st = st->next;
		new_st = push_stack(new_st, string);
		free(string);
	}
	return (reverse_stack(new_st));
}
