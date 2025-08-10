/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:34:24 by florent           #+#    #+#             */
/*   Updated: 2025/08/10 22:42:54 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print_error(char *string)
{
    ft_putstr_fd("error", 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd("\n", 1);
}

void    print_error_unknow_cmd(char *string)
{
    ft_putstr_fd("Error: command doesn't exist: ", 1);
    ft_putstr_fd(string, 1);
    ft_putstr_fd("\n", 1);
}