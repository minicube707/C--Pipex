/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:04:20 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/09 15:56:26 by fmotte           ###   ########.fr       */
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

static char *split_command_if(t_stack_string **stack, char *res, char *new_tmp, int *copy_mode)
{
    char    *tmp;

    tmp = duplicate_and_push(stack, res, new_tmp);
    if (tmp == NULL)
    {
        clear(res, NULL, NULL, new_tmp);
        free(tmp);
        return (NULL);
    }
	(*copy_mode)++;
	(*copy_mode) %= 2;
    return (tmp);
}

static char *split_command_else(t_stack_string **stack, char *res, char *new_tmp)
{
    char    *tmp;

    tmp = duplicate_and_push(stack, res, new_tmp);
    if (tmp == NULL)
    {
        clear(res, NULL, NULL, new_tmp);
        free(tmp);
        return (NULL);
    }
    return (tmp);
}

t_stack_string    *split_commmand(char *string)
{   
    t_stack_string	*stack;
    t_two_string    res;
    t_two_string    new_tmp;
	char			*tmp;
	int				copy_mode;

	tmp = ft_strdup(string);
	stack = new_stack();
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
	}
	free(tmp);
    stack = reverse_stack(stack);
	return (stack);
}
