/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:04:20 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/13 11:39:46 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clear(char *res1, char *res2, char *new_tmp1, char *new_tmp2)
{
	if (res1 != NULL)
		free(res1);
	if (res2 != NULL)
		free(res2);
	if (new_tmp1 != NULL)
		free(new_tmp1);
	if (new_tmp2 != NULL)
		free(new_tmp2);
	res1 = NULL;
	res2 = NULL;
	new_tmp1 = NULL;
	new_tmp2 = NULL;
}

static char	*split_command_if(t_stack_string **stack, char *res, char *new_tmp,
		int *copy_mode)
{
	char	*tmp;

	tmp = duplicate_and_push(stack, res, new_tmp);
	if (tmp == NULL)
		return (NULL);
	(*copy_mode)++;
	(*copy_mode) %= 2;
	return (tmp);
}

static char	*split_command_else(t_stack_string **stack, char *res,
		char *new_tmp)
{
	char	*tmp;

	tmp = duplicate_and_push(stack, res, new_tmp);
	return (tmp);
}

static	t_stack_string *split_command_loop(t_stack_string *stack, char *tmp)
{
	t_two_string	res;
	t_two_string	new_tmp;
	int				copy_mode;

	copy_mode = 0;
	while (*tmp != 0)
	{
		res.string1 = get_before_sep(tmp, &new_tmp.string1, '\'');
		res.string2 = get_before_sep(tmp, &new_tmp.string2, ' ');
		free(tmp);
		if (copy_mode || ft_strlen(res.string1) < ft_strlen(res.string2))
			tmp = split_command_if(&stack, res.string1, new_tmp.string1, &copy_mode);
		else
			tmp = split_command_else(&stack, res.string2, new_tmp.string2);
		clear(res.string1, res.string2, new_tmp.string1, new_tmp.string2);
		if (tmp == NULL)
			return (NULL);
	}
	free(tmp);
	return (stack);
}

t_stack_string	*split_commmand(char *string)
{
	t_stack_string	*stack;
	char			*tmp;

	stack = new_stack();
	if (*string == 0)
	{
		stack = push_stack(stack, "\0");
		return (stack);
	}
	tmp = ft_strdup(string);
	if (tmp == NULL)
		return (NULL);
	stack = split_command_loop(stack, tmp);
	if (stack == NULL)
		return (NULL);
	stack = reverse_stack(stack);
	return (stack);
}
