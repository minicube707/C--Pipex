/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:08:53 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 17:41:53 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_stack_string	*new_stack(void)
{
	return (NULL);
}

t_bool	is_empty_stack(t_stack_string *st)
{
	if (st == NULL)
		return (true);
	return (false);
}

t_stack_string	*push_stack(t_stack_string *st, char *string)
{
	t_stack_string	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		ft_putstr_fd("Probleme allocation dynamique with sactk\n", 1);
		clear_stack(st);
		return (NULL);
	}
	element->string = ft_strdup(string);
	if (element->string == NULL)
	{
		ft_putstr_fd("Probleme allocation dynamique with dup in stack\n", 1);
		clear_stack(st);
		free(element);
		return (NULL);
	}
	element->next = st;
	return (element);
}

t_stack_string	*clear_stack(t_stack_string *st)
{
	while ((!is_empty_stack(st)))
		st = pop_stack(st);
	return (new_stack());
}

t_stack_string	*pop_stack(t_stack_string *st)
{
	t_stack_string	*element;

	if (is_empty_stack(st))
		return (new_stack());
	element = st->next;
	free(st->string);
	free(st);
	return (element);
}
