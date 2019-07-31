/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:33:33 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/12 10:33:35 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclean(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		ft_memdel((void **)&lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;
	t_list		*head;
	t_list		*elem;

	if (!lst || !f)
		return (NULL);
	if (!(elem = f(lst)))
		return (NULL);
	if (!(result = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	head = result;
	while (lst)
	{
		elem = f(lst);
		if (!(result->next = ft_lstnew(elem->content, elem->content_size)))
		{
			ft_lstclean(head);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
