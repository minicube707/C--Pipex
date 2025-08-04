/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:08:41 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 22:38:54 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_stack_string	*inversion_stack(t_stack_string *st)
{
	t_stack_string	*new_st;

	new_st = new_stack();
	while (st != NULL)
	{
		new_st = push_stack(new_st, st->string);
		if (new_st == NULL)
		{
			clear_stack(st);
			return (NULL);
		}
		st = pop_stack(st);
	}
	return (new_st);
}
