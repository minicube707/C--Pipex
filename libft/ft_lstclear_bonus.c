/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:14:07 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/05 13:59:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next_tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		next_tmp = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next_tmp;
	}
	*lst = NULL;
}
