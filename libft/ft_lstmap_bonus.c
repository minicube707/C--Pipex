/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:15:02 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/05 17:12:37 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*first_p(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	void	*tmp;

	begin = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	tmp = f(lst->content);
	begin = ft_lstnew(tmp);
	if (begin == NULL)
	{
		del (tmp);
		return (NULL);
	}
	return (begin);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;
	void	*tmp;

	begin = first_p(lst, f, del);
	if (begin == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			del (tmp);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
