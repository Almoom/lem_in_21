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

t_lst	*create_list(char *s)
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

t_lst	*creator(t_lst *head, char *s)
{
	t_lst *tmp;

	tmp = head;
	if (not_comment(s))
	{
		if (!head)
		{
			head = create_list(s);
			tmp = head;
			if (check_realnum(s))
				head->isnum = 1;
		}
		else
		{
			while (head->next)
				head = head->next;
			head->next = create_list(s);
		}
	}
	return (tmp);
}

void	del_roll(t_lst **head)
{
	t_lst *tmp;

	if (!(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list(head);
		*head = tmp;
	}
}

// int		check_void(t_lst *head)
// {
// 	t_lst *tmp;
//
// 	tmp = head;
// 	if (!head)
// 		return (FALSE);
// 	while (tmp->next)
// 	{
// 		if (!ft_strcmp(tmp->line, ""))
// 			return (FALSE);
// 		tmp = tmp->next;
// 	}
// 	if (!ft_strcmp(tmp->line, ""))
// 		return (FALSE);
// 	return (TRUE);
// }

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
			if (((a->name && b->name && !ft_strcmp(a->name, b->name) && a != b)
			|| (a->x_y && b->x_y && !ft_strcmp(a->x_y, b->x_y) && a != b))
			&& ft_strcmp(a->line, b->line))
				a->isxy = 0;
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

void	del_list(t_lst **del)
{
	ft_memdel((void**)(&(*del)->line));
	ft_memdel((void**)(&(*del)->name));
	ft_memdel((void**)(&(*del)->x_y));
	ft_memdel((void**)(&(*del)->name1));
	ft_memdel((void**)(&(*del)->name2));
	free(*del);
}

t_lst	*check_dupl_names(t_lst **head)
{
	t_lst *tmp_prev;
	t_lst *h;

	h = *head;
	if (!(*head))
		return (NULL);
	while ((*head))
	{
		if ((*head)->name1 && (*head)->name2 && !ft_strcmp
		((*head)->name1, (*head)->name2))
		{
			tmp_prev->next = (*head)->next;
			del_list(head);
			(*head) = tmp_prev->next;
		}
		else
		{
			tmp_prev = (*head);
			(*head) = (*head)->next;
		}
	}
	return (h);
}

void 	check_new_names(t_lst *a, t_lst *b)
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
	if (start != 1 || end != 1)
		return (FALSE);
	return (TRUE);
}

// void	check_dupl_edge(t_lst *a, t_lst *b)
// {
// 	t_lst *tmp;
// 	// int flag;
// 	//
// 	// flag = 0;
// 	tmp = b;
// 	if (!a || !b)
// 		return ;
// 	while (a)
// 	{
// 		while (b)
// 		{
// 			if (a->isedge == 1 && b->isedge == 1 && ft_strcmp(a->line, b->line) && !ft_strcmp(a->name1, b->name1) && !ft_strcmp(a->name2, b->name2))
// 			{
//
// 				printf("%s\n", a->line);
// 					a->isedge = 0;
// 			}
// 			b = b->next;
// 		}
//
// 		b = tmp;
// 		a = a->next;
// 	}
// 	// t_lst *h;
// 	// t_lst *tmp_prev;
// 	// int flag;
// 	//
// 	// h = *b;
// 	// flag = 0;
// 	// if (!(*a) || !(*b))
// 	// 	return (NULL);
// 	// while ((*a))
// 	// {
// 	// 	while ((*b))
// 	// 	{
// 	// 		if ((*a)->isedge == 1 && (*b)->isedge == 1
// 	// 		&& !ft_strcmp((*a)->name1, (*b)->name2)
// 	// 		&& !ft_strcmp((*a)->name2, (*b)->name1) && (*b)->next)
// 	// 		{
// 	// 			printf("%s\n", "");
// 	// 			tmp_prev->next = (*b)->next;
// 	// 			del_list(b);
// 	// 			(*b) = tmp_prev->next;
// 	// 			break;
// 	// 		}
// 	// 		else
// 	// 		{
// 	// 			tmp_prev = *b;
// 	// 			(*b) = (*b)->next;
// 	// 		}
// 	// 	}
// 	// 	(*b) = h;
// 	// 	(*a) = (*a)->next;
// 	// }
// 	// return (h);
// }

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
	//Валидация
	check_xy(head);
	split_name_xy(head);
	check_dupl_xy(head, head);
	check_commands(head);
	head = split_names(&head);
	check_new_names(head, head);
	if (checker(head))
		printer(head);
	else
		ft_putendl("ERROR");
	//Модификация
	printf("\n");
	head = check_dupl_names(&head);

	//check_dupl_edge(head, head);
	printer(head);

	del_roll(&head);
	return (0);
}
