/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:37:38 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/16 13:45:48 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing_command(t_stack_string **stack_env, t_super_list **super_list,
		t_file_fd *file_fd)
{
	t_super_list	*tmp;
	int				len;

	tmp = *super_list;
	len = lenght_super_list(tmp);
	while (len--)
	{
		if (check_command(stack_env, tmp->tab_string))
		{
			clear_stack(*stack_env);
			clear_super_list(*super_list);
			return (1);
		}
		tmp->file_fd = file_fd;
		tmp = tmp->next;
	}
	if (lenght_super_list(*super_list) < 2)
	{
		clear_stack(*stack_env);
		clear_super_list(*super_list);
		print_error("insufficient number of command");
		return (1);
	}
	return (0);
}
