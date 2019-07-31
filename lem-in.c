/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:01:31 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/25 17:01:32 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	printer(t_lst *head)
{
	t_lst *tmp;

	tmp = head;
	if (!tmp)
	{
		printf("%s\n", "NULL");
		return ;
	}
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

t_lst	*create_list(char *s)
{
	t_lst *list;

	if (!(list = (t_lst*)malloc(sizeof(*list))))
		return (NULL);
	list->line = ft_strdup(s);
	list->next = NULL;
	return (list);
}

t_lst	*creator(t_lst *head, char *s)
{
	t_lst *tmp;

	tmp = head;
	if (!head)
	{
		head = create_list(s);
		tmp = head;
	}
	else
	{
		while (head->next)
			head = head->next;
		if (!(s[0] == '#' && s[1] != '#'))
			head->next = create_list(s);
	}
	return (tmp);
}

void	del_roll(t_lst **head)
{
	t_lst *t;

	while ((*head)->next)
	{
		t = (*head)->next;
		ft_memdel((void**)(&(*head)->line));
		free(*head);
		*head = t;
	}
	ft_memdel((void**)(&(*head)->line));
	free(*head);
}

int		main(void)
{
	t_lst *head;
	char *arr;

	head = NULL;
	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		head = creator(head, arr);
		ft_memdel((void**)(&arr));
	}
	ft_memdel((void**)(&arr));
	printer(head);
	del_roll(&head);
	return (0);
}
