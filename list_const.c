/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_const.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:21:01 by ljalikak          #+#    #+#             */
/*   Updated: 2019/08/18 16:21:03 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	read_const(t_val *map)
{
	t_val	*h;
	t_const *list;

	h = map;
	if (!(list = create_list_const(0, NULL, NULL)))
		return ;
	while (map)
	{
		if (map->isedge)
			break ;
		list->ants = map->isnum ? ft_atoi(map->line) : list->ants;
		if (map->isstart)
		{
			free(list->start);
			list->start = ft_strdup(map->next->name);
		}
		if (map->isend)
		{
			free(list->end);
			list->end = ft_strdup(map->next->name);
		}
		map = map->next;
	}
	//modify(list, scrolling_valid(h)); //------------- передаю лист констант и список ТОЛЬКО РЕБЕР
	del_list_const(&list);
}

t_const	*create_list_const(int ants, char *start, char *end)
{
	t_const *list;

	if (!(list = (t_const*)malloc(sizeof(*list))))
		return (NULL);
	list->ants = ants;
	list->start = start ? ft_strdup(start) : NULL;
	list->end = end ? ft_strdup(end) : NULL;
	return (list);
}

void	del_list_const(t_const **list)
{
	free((*list)->start);
	free((*list)->end);
	free(*list);
}

t_val	*scrolling_valid(t_val *map)
{
	if (!map)
		return (NULL);
	while (map)
	{
		if (map->isedge)
			break ;
		map = map->next;
	}
	return (map);
}
