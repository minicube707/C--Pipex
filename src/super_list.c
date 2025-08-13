/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:39:39 by fmotte            #+#    #+#             */
/*   Updated: 2025/08/13 10:22:21 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_super_list	*new_super_list(void)
{
	return (NULL);
}

/*--------------------------------------------------*/
/**
 * Vérifie si une List est vide
 * @return true si la List est vide, faux sinon
 */
t_bool	is_empty_super_list(t_super_list *li)
{
	if (li == NULL)
		return (true);
	return (false);
}

/*--------------------------------------------------*/
/**
 * Retourne la hauteur (longueur) de la List
 * @return La taille de la List
 */
int	lenght_super_list(t_super_list *li)
{
	int	size;

	size = 0;
	if (!is_empty_super_list(li))
	{
		while (li != NULL)
		{
			++size;
			li = li->next;
		}
	}
	return (size);
}

/*--------------------------------------------------*/
/**
 * Affiche une Queue
 * @param li La List
 */
void	print_super_list(t_super_list *li)
{
	if (is_empty_super_list(li))
	{
		printf("La Super list est vide, rien a afficher \n");
		return ;
	}
	while (li != NULL)
	{
		print_tab(li->tab_string);
		li = li->next;
	}
}

/*--------------------------------------------------*/
/**
 * Ajoute un entier à la fin de la List
 * @param li La List
 * @param val Un entier
 * @return La nouvelle List
 */
t_super_list	*put_super_back(t_super_list *su, char **tab)
{
	t_super_list	*tmp;
	t_super_list	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		print_error("Dynamic allocation issue with new element in super list");
		return (NULL);
	}
	element->tab_string = copy_tab(tab);
	if (element->tab_string == NULL)
	{
		clear_super_list(su);
		return (NULL);
	}
	element->next = NULL;
	if (is_empty_super_list(su))
		return (element);
	tmp = su;
	tmp = bot_super_list(su);
	tmp->next = element;
	return (su);
}
