/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:45:45 by florent           #+#    #+#             */
/*   Updated: 2025/08/13 00:46:09 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*--------------------------------------------------*/
/**
 * Retire le premier élément de la List
 * @param li La List
 * @return La nouvelle List
 */
t_super_list	*pop_super_front(t_super_list *li)
{
	t_super_list	*new_first;

	if (is_empty_super_list(li))
		return (li);
	new_first = li->next;
	clear_tab(li->tab_string);
	li->tab_string = NULL;
	free(li);
	li = NULL;
	return (new_first);
}

/*--------------------------------------------------*/
/**
 * Vide la List de ses éléments
 * @param li La List
 * @return La nouvelle List vide
 */
t_super_list	*clear_super_list(t_super_list *li)
{
	if (is_empty_super_list(li))
		return (new_super_list());
	while (li != NULL)
	{
		li = pop_super_front(li);
	}
	return (li);
}
