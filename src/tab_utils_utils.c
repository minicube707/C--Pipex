/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:30:56 by florent           #+#    #+#             */
/*   Updated: 2025/08/13 00:47:50 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**fill_tab(t_stack_string *tmp, char **tab)
{
	int	i;

	i = 0;
	while (tmp != NULL)
	{
		if (*tmp->string != 0)
		{
			tab[i] = ft_strdup(tmp->string);
			if (tab[i] == NULL)
			{
				print_error("Problem allocation with new element in tab");
				clear_tab(tab);
				return (NULL);
			}
			i++;
		}
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

static int	count_no_mt_stack(t_stack_string *tmp)
{
	int	size;

	size = 1;
	while (tmp != NULL)
	{
		if (*tmp->string != 0)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**stack_to_tab(t_stack_string *stack)
{
	char	**tab;
	int		size;

	if (stack == NULL)
		return (NULL);
	size = count_no_mt_stack(stack);
	tab = malloc(size * sizeof(char *));
	if (tab == NULL)
	{
		print_error("Problem allocation with creation of tab");
		return (NULL);
	}
	tab = fill_tab(stack, tab);
	clear_stack(stack);
	return (tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
