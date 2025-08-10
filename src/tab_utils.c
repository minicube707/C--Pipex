/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 02:24:33 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/10 23:54:27 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char **fill_tab(t_stack_string *tmp, char **tab)
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

static 	int count_no_mt_stack(t_stack_string *tmp)
{
	int size;
	
	size = 1;
	while (tmp != NULL)
	{
		if (*tmp->string != 0)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

static 	void error_alloc(char **new_tab, char **tab)
{
	print_error("Problem allocation with new element in tab");
	clear_tab(tab);
	clear_tab(new_tab);
}

int		lenght_tab(char **tab)
{
	int		nb_elem;

	nb_elem = 0;
	while (tab[nb_elem] != NULL)
		nb_elem++;
	nb_elem++;
	return(nb_elem);
}

char	**copy_tab(char **tab)
{
	char	**new_tab;
	int		nb_elem;
	int		i;
	
	nb_elem = lenght_tab(tab);
	new_tab = malloc(nb_elem * sizeof(char **));
	if (new_tab == NULL)
	{
		print_error("Problem allocation with creation of tab");
		return (NULL);
	}
	i = 0;
	while (i < nb_elem - 1)
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (new_tab[i] == NULL)
		{
			error_alloc(new_tab, tab);
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
	char			**tab;
	int				size;

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
