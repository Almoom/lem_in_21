/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:19:58 by ljalikak          #+#    #+#             */
/*   Updated: 2019/08/18 14:20:01 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	check_dupl_xy(t_val *a, t_val *b)
{
	t_val *tmp;

	tmp = b;
	if (!a || !b)
		return ;
	while (a->next)
	{
		while (b->next)
		{
			if (a->isxy && b->isxy && ft_strcmp(a->line, b->line) && a != b)
				if (((ft_strcmp(a->name, b->name) && !ft_strcmp(a->x_y, b->x_y))
				|| (!ft_strcmp(a->name, b->name) && ft_strcmp(a->x_y, b->x_y))))
					a->isxy = 0;
			b = b->next;
		}
		b = tmp;
		a = a->next;
	}
}

void	check_dupl_start(t_val *head)
{
	char *tmp;

	tmp = NULL;
	while (head->next)
	{
		if (head->isstart)
			break ;
		head = head->next;
	}
	if (head->next)
		tmp = ft_strdup(head->next->line);
	head = head->next;
	while (head && head->next)
	{
		if (head->isstart && ft_strcmp(head->next->line, tmp))
			head->isstart = 0;
		head = head->next;
	}
	ft_memdel((void**)(&tmp));
}

void	check_dupl_end(t_val *head)
{
	char *tmp;

	tmp = NULL;
	while (head->next)
	{
		if (head->isend)
			break ;
		head = head->next;
	}
	if (head->next)
		tmp = ft_strdup(head->next->line);
	head = head->next;
	while (head && head->next)
	{
		if (head->isend && ft_strcmp(head->next->line, tmp))
			head->isend = 0;
		head = head->next;
	}
	ft_memdel((void**)(&tmp));
}
