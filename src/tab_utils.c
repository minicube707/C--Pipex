/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:24:33 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/09 16:32:46 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**copy_tab(char **tab)
{
	char	**new_tab;
	int		nb_elem;
	int		i;

	nb_elem = 0;
	while (tab[nb_elem] != NULL)
		nb_elem++;
	nb_elem++;
	new_tab = malloc(nb_elem * sizeof(char **));
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (i < nb_elem - 1)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (new_tab[i] == NULL)
		{
			clear_tab(tab);
			clear_tab(new_tab);
			return (NULL);
		}
		new_tab[i + 1] = NULL;
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
char	**stack_to_tab(t_stack_string *stack)
{
	t_stack_string	*tmp;
	char			**tab;
	int				size;
	int				i;

	size = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		if (*tmp->string != 0)
			size++;
		tmp = tmp->next;
	}
	tab = malloc(size * sizeof(char *));
	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		if (*tmp->string != 0)
			tab[i++] = ft_strdup(tmp->string);
		tmp = tmp->next;
	}
	tab[i] = NULL;
    clear_stack(stack);
	return (tab);
}
