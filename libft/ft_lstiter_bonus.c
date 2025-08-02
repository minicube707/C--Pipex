/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:14:35 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/05 14:01:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	void	*tmp_content;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp_content = tmp->content;
		(f)(tmp_content);
		tmp->content = tmp_content;
		tmp = tmp->next;
	}
}
