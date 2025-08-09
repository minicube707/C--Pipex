/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:16:47 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/09 15:19:11 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_nb_quote(char *string)
{
	int	i;
	int	nb_quote;

	i = 0;
	nb_quote = 0;
	while (string[i] != 0)
	{
		if (string[i] == '\'')
			nb_quote++;
		i++;
	}
	return (nb_quote);
}

int	check_nb_quote(char *string, t_super_list *super_list)
{
	int	nb_quote;

	nb_quote = count_nb_quote(string);
	if (nb_quote % 2 == 1)
	{
		ft_putstr_fd("error: insufficient number of quote\n", 1);
		clear_super_list(super_list);
		return (1);
	}
	return (0);
}
