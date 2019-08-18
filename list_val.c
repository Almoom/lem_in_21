/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:23:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/08/18 13:23:23 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_val	*create_list_valid(char *s)
{
	t_val *list;

	if (!(list = (t_val*)malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	list->line = ft_strdup(s);
	list->name = NULL;
	list->x_y = NULL;
	list->name1 = NULL;
	list->name2 = NULL;
	list->isnum = 0;
	list->isstart = 0;
	list->isend = 0;
	list->isxy = 0;
	list->isedge = 0;
	return (list);
}

t_val	*creator_valid(t_val *head, char *s)
{
	t_val *tmp;

	tmp = head;
	while (head->next)
	{
		head = head->next;
	}
	head->next = create_list_valid(s);
	return (tmp);
}

void	printer_valid(t_val *head)
{
	if (!head)
		return ;
	while (head)
	{
		ft_putstr(ft_itoa(head->isnum));
		ft_putstr("\t");
		ft_putstr(ft_itoa(head->isstart));
		ft_putstr("\t");
		ft_putstr(ft_itoa(head->isend));
		ft_putstr("\t");
		ft_putstr(ft_itoa(head->isxy));
		ft_putstr("\t");
		ft_putstr(ft_itoa(head->isedge));
		ft_putstr("\t");
		ft_putstr(head->name);
		ft_putstr("\t");
		ft_putstr(head->x_y);
		ft_putstr("\t");
		ft_putstr(head->name1);
		ft_putstr("\t");
		ft_putstr(head->name2);
		ft_putstr("\t");
		ft_putendl(head->line);
		head = head->next;
	}
}

void	del_list_valid(t_val **del)
{
	ft_memdel((void**)(&(*del)->line));
	ft_memdel((void**)(&(*del)->name));
	ft_memdel((void**)(&(*del)->x_y));
	ft_memdel((void**)(&(*del)->name1));
	ft_memdel((void**)(&(*del)->name2));
	free(*del);
}

void	del_roll_valid(t_val **head)
{
	t_val *tmp;

	if (!(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_valid(head);
		*head = tmp;
	}
}
