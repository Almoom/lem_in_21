/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:01 by ljalikak          #+#    #+#             */
/*   Updated: 2019/08/18 14:27:03 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		main(void) 	//---------------------------- читаем карту в список t_val
{
	t_val	*head;
	char	*arr;

	head = NULL;
	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		ft_putendl(arr);
		if (!head && not_comment(arr) && check_realnum(arr))
		{
			head = create_list_valid(arr);
			head->isnum = 1;
		}
		else if (head && not_comment(arr))
			head = creator_valid(head, arr);
		ft_memdel((void**)(&arr));
	}
	if (head)
		ft_putchar('\n');
	ft_memdel((void**)(&arr));
	lemin(&head); //-------------------------------- проверяем валидность карты
	del_roll_valid(&head);
	return (0);
}

void	lemin(t_val **head)
{
	if ((*head))
	{
		check_xy(*head);
		split_name_xy(*head);
		check_dupl_xy(*head, *head);
		check_commands(*head);
		check_dupl_start(*head);
		check_dupl_end(*head);
		*head = split_names(head);
		check_new_names(*head, *head);
		if (checker(*head))
			read_const(*head); //----------- конец валидации
		else
			ft_putendl("ERROR");
	}
	else
		ft_putendl("ERROR");
}

int		checker(t_val *head)
{
	t_val	*t;
	int		start;
	int		end;

	start = 0;
	end = 0;
	t = head;
	if (!head)
		return (FALSE);
	while (t)
	{
		if (t->isnum + t->isstart + t->isend + t->isxy + t->isedge != 1)
			return (FALSE);
		if (t->isstart == 1)
			start++;
		if (t->isend == 1)
			end++;
		t = t->next;
	}
	if (start == 0 || end == 0)
		return (FALSE);
	return (TRUE);
}

void	check_commands(t_val *head)
{
	t_val *tmp;

	tmp = head;
	if (!head)
		return ;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->line, "##start") && tmp->next->isxy == 1)
			tmp->isstart = 1;
		if (!ft_strcmp(tmp->line, "##end") && tmp->next->isxy == 1)
			tmp->isend = 1;
		tmp = tmp->next;
	}
}

void	check_new_names(t_val *a, t_val *b)
{
	t_val	*tmp;
	int		flag;

	flag = 0;
	tmp = b;
	if (!a || !b)
		return ;
	while (a->next)
	{
		while (b->next)
		{
			if (b->name && a->name1 && a->name2
			&& (!ft_strcmp(b->name, a->name1) || !ft_strcmp(b->name, a->name2)))
				flag = 1;
			b = b->next;
		}
		if (flag == 0)
			a->isedge = 0;
		else
			flag = 0;
		b = tmp;
		a = a->next;
	}
}
