/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:56:07 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/10 23:50:15 by florent          ###   ########.fr       */
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
		if (string == NULL)
		{
			print_error("Dynamic allocation issue in reverse_stack content");
			clear_stack(st);
			return (NULL);
		}
		st = pop_stack(st);
		new_st = push_stack(new_st, string);
		if (new_st == NULL)
		{
			clear_stack(st);
			return (NULL);
		}
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
		if (string == NULL)
		{
			print_error("Dynamic allocation issue in copy_stack content");
			clear_stack(st);
			return (NULL);
		}
		st = st->next;
		new_st = push_stack(new_st, string);
		if (string == NULL)
		{
			clear_stack(st);
			return (NULL);
		}
		free(string);
	}
	return (reverse_stack(new_st));
}
