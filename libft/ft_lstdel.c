/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:31:54 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/11 16:46:23 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		t = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = t;
	}
}
