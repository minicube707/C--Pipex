/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:40:33 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/04 22:48:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_file(t_file *file)
{
    free(file->infile);
    free(file->outfile);
    file = NULL;
}

void    free_all(t_stack_string	*stack_env, t_stack_string	*stack_cmd, t_file *file)
{
    if (stack_env != NULL)
        clear_stack(stack_env);
    if (stack_cmd != NULL)
        clear_stack(stack_cmd);
    if (file != NULL)
        free_file(file);
}