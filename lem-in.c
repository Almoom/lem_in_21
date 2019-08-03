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

void	printer_valid(t_lst *head)
{
	t_lst *tmp;

	tmp = head;
	if (!tmp)
	{
		printf("%s\n", "(пусто)");
		return ;
	}
	while (tmp)
	{
		printf("%d\t", tmp->isnum);
		printf("%d\t", tmp->isstart);
		printf("%d\t", tmp->isend);
		printf("%d\t", tmp->isxy);
		printf("%d\t", tmp->isedge);
		printf("%s\t", tmp->name);
		printf("%s\t", tmp->x_y);
		printf("%s\t", tmp->name1);
		printf("%s\t", tmp->name2);
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

void	printer_mod(t_l *head)
{
	t_l *tmp;

	tmp = head;
	if (!tmp)
	{
		printf("%s\n", "(пусто)");
		return ;
	}
	while (tmp)
	{
		printf("%s\t", tmp->line);
		printf("%s\t", tmp->name1);
		printf("%s\t", tmp->name2);
		printf("%d\t", tmp->ants);
		printf("%s\t", tmp->start);
		printf("%s\n", tmp->end);
		tmp = tmp->next;
	}
}

t_lst	*create_list_valid(char *s)
{
	t_lst *list;

	if (!(list = (t_lst*)malloc(sizeof(*list))))
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

int		not_comment(char *s)
{
	if (s[0] == '#' && s[1] != '#')
		return (FALSE);
	if (s[0] == '#' && s[1] == '#')
	{
	 	if (!ft_strcmp(s, "##start") || !ft_strcmp(s, "##end"))
			return (TRUE);
		else
			return (FALSE);
	}
	return (TRUE);
}

int		check_realnum_add(char *s, int n, int len)
{
	int i;

	i = 0;
	while (i < n)
	{
		s++;
		i++;
	}
	if (len < 10)
		return (TRUE);
	if (len == 10 && ft_strcmp(s, "2147483647") <= 0)
			return (TRUE);
	return (FALSE);
}

int		check_realnum(char *s)
{
	int i;
	int j;
	int flag;

	i = -1;
	j = 0;
	flag = 0;
	while (s[++i])
	{
		if (i == 0 && s[i] == '-')
			return (FALSE);
		if (i == 0 && s[i] == '+')
			i++;
		if (!s[i] || !ft_isdigit(s[i]))
			return (FALSE);
		while (s[i] == '0' && flag == 0)
			i++;
		if (!s[i])
			return (TRUE);
		if (!ft_isdigit(s[i]))
			return (FALSE);
		if (ft_isdigit(s[i]) && j++ <= i)
			flag = 1;
	}
	return (check_realnum_add(s, i - j, j));
}

t_lst	*creator_valid(t_lst *head, char *s)
{
	t_lst *tmp;

	tmp = head;
	if (not_comment(s))
	{
		if (!head)
		{
			head = create_list_valid(s);
			tmp = head;
			if (check_realnum(s))
				head->isnum = 1;
		}
		else
		{
			while (head->next)
				head = head->next;
			head->next = create_list_valid(s);
		}
	}
	return (tmp);
}

void	del_roll_valid(t_lst **head)
{
	t_lst *tmp;

	if (!(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_valid(head);
		*head = tmp;
	}
}

int		num_w(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	del_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int 		num_c(char *s, int ch)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ch)
			count++;
		i++;
	}
	return (count);
}

void	check_edge(t_lst *head)
{
	t_lst *tmp;
	char **av;

	if (!head)
		return ;
	tmp = head;
	while (tmp->next)
	{
		av = ft_strsplit(tmp->line, '-');
		if (num_w(av) == 2 && num_c(tmp->line, '-') == 1)
			tmp->isedge = 1;
		else
		{
			del_split(av);
			return ;
		}
		del_split(av);
		tmp = tmp->next;
	}
	av = ft_strsplit(tmp->line, '-');
	if (num_w(av) == 2 && num_c(tmp->line, '-') == 1)
		tmp->isedge = 1;
	del_split(av);
}

void	check_xy(t_lst *head)
{
	t_lst *tmp;
	char **av;

	if (!head)
		return ;
	if (head->next)
		tmp = head->next;
	while (tmp->next)
	{
		av = ft_strsplit(tmp->line, ' ');
		if (num_w(av) == 3 || !ft_strcmp(tmp->line, "##start")
		|| !ft_strcmp(tmp->line, "##end"))
		{
			if (num_w(av) == 3 && check_realnum(av[1]) && check_realnum(av[2])
			&& av[0][0] != 'L')
				tmp->isxy = 1;
		}
		else
			break;
		del_split(av);
		tmp = tmp->next;
	}
	del_split(av);
	check_edge(tmp);
}

void	check_commands(t_lst *head)
{
	t_lst *tmp;

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

void	split_name_xy(t_lst *head)
{
	t_lst *tmp;
	char **av;

	tmp = head;
	if (!head)
		return ;
	while (tmp->next)
	{
		if (tmp->isxy == 1)
		{
			av = ft_strsplit(tmp->line, ' ');
			tmp->name = ft_strdup(av[0]);
			tmp->x_y = ft_strjoin_free(ft_strjoin(av[1], " "), av[2], 1, 0);
			del_split(av);
		}
		tmp = tmp->next;
	}
}

void	check_dupl_xy(t_lst *a, t_lst *b)
{
	t_lst *tmp;

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
			// if ((a->name && b->name && ft_strcmp(a->name, b->name)
			// && a->x_y && b->x_y && !ft_strcmp(a->x_y, b->x_y) && a != b)
			// || (a->name && b->name && !ft_strcmp(a->name, b->name)
			// && a->x_y && b->x_y && ft_strcmp(a->x_y, b->x_y) && a != b))
			b = b->next;
		}
		b = tmp;
		a = a->next;
	}
}

t_lst	*split_names(t_lst **head)
{
	t_lst *tmp;
	char **av;

	tmp = *head;
	if (!head)
		return (NULL);
	while (tmp)
	{
		if (tmp->isedge == 1)
		{
			av = ft_strsplit(tmp->line, '-');
			tmp->name1 = ft_strcmp(av[0], av[1]) < 0 ?
			ft_strdup(av[0]) : ft_strdup(av[1]);
			tmp->name2 = ft_strcmp(av[0], av[1]) < 0 ?
			ft_strdup(av[1]) : ft_strdup(av[0]);
			free(tmp->line);
			tmp->line = ft_strjoin_free
			(ft_strjoin(tmp->name1, "-"), tmp->name2, 1, 0);
			del_split(av);
		}
		tmp = tmp->next;
	}
	return (*head);
}

void	del_list_valid(t_lst **del)
{
	ft_memdel((void**)(&(*del)->line));
	ft_memdel((void**)(&(*del)->name));
	ft_memdel((void**)(&(*del)->x_y));
	ft_memdel((void**)(&(*del)->name1));
	ft_memdel((void**)(&(*del)->name2));
	free(*del);
}

void	check_new_names(t_lst *a, t_lst *b)
{
	t_lst *tmp;
	int flag;

	flag = 0;
	tmp = b;
	if (!a || !b)
		return ;
	while (a->next)
	{
		while (b->next)
		{
			if (b->name && a->name1 && a->name2 && (!ft_strcmp
				(b->name, a->name1) || !ft_strcmp(b->name, a->name2)))
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

int		checker(t_lst *head)
{
	t_lst *t;
	int start;
	int end;

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

t_l		*create_list_mod(int ants, char *start, char *end, t_lst *map)
{
	t_l *list;

	if (!(list = (t_l*)malloc(sizeof(*list))))
		return (NULL);
	list->line = ft_strdup(map->line);
	list->name1 = ft_strdup(map->name1);
	list->name2 = ft_strdup(map->name2);
	list->ants = ants;
	list->start = ft_strdup(start);
	list->end = ft_strdup(end);
	return (list);
}

t_l		*creator_mod(t_l *head, t_lst *map)
{
	t_l *tmp;

	tmp = head;
	while (head->next)
	{
		if (!ft_strcmp(map->line, head->line))
			return (tmp);
		head = head->next;
	}
	if (!ft_strcmp(map->line, head->line))
		return (tmp);
	head->next = create_list_mod(tmp->ants, tmp->start, tmp->end, map);
	return (tmp);
}

void	del_list_mod(t_l **del)
{
	ft_memdel((void**)(&(*del)->line));
	ft_memdel((void**)(&(*del)->name1));
	ft_memdel((void**)(&(*del)->name2));
	ft_memdel((void**)(&(*del)->start));
	ft_memdel((void**)(&(*del)->end));
	free(*del);
}

void	del_roll_mod(t_l **head)
{
	t_l *tmp;

	if (!(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_mod(head);
		*head = tmp;
	}
}

void	modify(int ants, char *start, char *end, t_lst *map)
{
	t_l *head;

	head = NULL;
	while (map)
	{
		if (map->isedge)
			break;
		map = map->next;
	}
	if (!map)
		return ;
	head = create_list_mod(ants, start, end, map);
	if (map->next)
		map = map->next;
	while (map)
	{
		if (map->name1 && map->name2 && ft_strcmp(map->name1, map->name2))
			head = creator_mod(head, map);
		map = map->next;
	}
	printer_mod(head);
	del_roll_mod(&head);
}

void	read_and_modify(t_lst *map, char *start, char *end)
{
	t_lst *h;
	int ants;

	h = map;
	while (map)
	{
		ants = map->isnum ? ft_atoi(map->line) : ants;
		if (map->isstart)
		{
			free(start);
			start = ft_strdup(map->line);
		}
		if (map->isend)
		{
			free(end);
			end = ft_strdup(map->line);
		}
		map = map->next;
	}
	modify(ants, start, end, h);
	free(start);
	free(end);
}

// t_lst	*check_dupl_names(t_lst **head)
// {
// 	t_lst *tmp_prev;
// 	t_lst *h;
//
// 	h = *head;
// 	if (!(*head))
// 		return (NULL);
// 	while ((*head))
// 	{
// 		if ((*head)->name1 && (*head)->name2 && !ft_strcmp
// 		((*head)->name1, (*head)->name2))
// 		{
// 			tmp_prev->next = (*head)->next;
// 			del_list(head);
// 			(*head) = tmp_prev->next;
// 		}
// 		else
// 		{
// 			tmp_prev = (*head);
// 			(*head) = (*head)->next;
// 		}
// 	}
// 	return (h);
// }

void 	check_dupl_start(t_lst *head)
{
	char *tmp;

	tmp = NULL;
	while (head->next)
	{
		if (head->isstart)
			break;
		head = head->next;
	}
	tmp = ft_strdup(head->next->line);
	head = head->next;
	while (head->next)
	{
		if (head->isstart && ft_strcmp(head->next->line, tmp))
			head->isstart = 0;
		head = head->next;
	}
	ft_memdel((void**)(&tmp));
}

void 	check_dupl_end(t_lst *head)
{
	char *tmp;

	tmp = NULL;
	while (head->next)
	{
		if (head->isend)
			break;
		head = head->next;
	}
	tmp = ft_strdup(head->next->line);
	head = head->next;
	while (head->next)
	{
		if (head->isend && ft_strcmp(head->next->line, tmp))
			head->isend = 0;
		head = head->next;
	}
	ft_memdel((void**)(&tmp));
}

void 	lemin(t_lst **head)
{
	check_xy(*head);
	split_name_xy(*head);
	check_dupl_xy(*head, *head);
	check_commands(*head);
	check_dupl_start(*head);
	check_dupl_end(*head);
	*head = split_names(head);
	check_new_names(*head, *head);
	printer_valid(*head);
	if (checker(*head))
		read_and_modify(*head, NULL, NULL); //----- Модификация
	else
		ft_putendl("ERROR");
}

int		main(void) 	//-----------------------------Валидация
{
	t_lst *head;
	char *arr;

	head = NULL;
	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		head = creator_valid(head, arr);
		ft_memdel((void**)(&arr));
	}
	ft_memdel((void**)(&arr));
	lemin(&head);
	del_roll_valid(&head);
	return (0);
}
