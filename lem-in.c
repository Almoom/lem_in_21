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

void	printer_valid(t_val *head)
{
	t_val *tmp;

	tmp = head;
	if (!tmp)
	{
		ft_putendl("(пусто)");
		return ;
	}
	while (tmp)
	{
		ft_putstr(ft_itoa(tmp->isnum));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->isstart));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->isend));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->isxy));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->isedge));
		ft_putstr("\t");
		if (tmp->name)
			ft_putstr(tmp->name);
		ft_putstr("\t");
		if (tmp->x_y)
			ft_putstr(tmp->x_y);
		ft_putstr("\t");
		if (tmp->name1)
			ft_putstr(tmp->name1);
		ft_putstr("\t");
		if (tmp->name2)
			ft_putstr(tmp->name2);
		ft_putstr("\t");
		if (tmp->line)
			ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}

void	printer_mod(t_mod *head)
{
	t_mod *tmp;

	tmp = head;
	if (!tmp)
	{
		ft_putendl("(пусто)");
		return ;
	}
	ft_putendl("line\t\tw\tname1\tc1\tname2\tc2\tloc\tants\tstart\tend\n");
	while (tmp)
	{
		if (tmp->line)
			ft_putstr(tmp->line);
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->weight));
		ft_putstr("\t");
		if (tmp->name1)
			ft_putstr(tmp->name1);
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->c1));
		ft_putstr("\t");
		if (tmp->name2)
			ft_putstr(tmp->name2);
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->c2));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->loc));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->ants));
		ft_putstr("\t");
		if (tmp->start)
			ft_putstr(tmp->start);
		ft_putstr("\t");
		if (tmp->end)
			ft_putstr(tmp->end);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	printer_way(t_way *head)
{
	t_way *tmp;

	tmp = head;
	if (!tmp)
	{
		ft_putendl("(пусто)");
		return ;
	}
	ft_putendl("name\tlen\tants\ta_w\tn_a\tstart\tend\n");
	while (tmp)
	{
		if (tmp->name)
			ft_putstr(tmp->name);
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->len));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->ants));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->ants_way));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->num_ant));
		ft_putstr("\t");
		if (tmp->start)
			ft_putstr(tmp->start);
		ft_putstr("\t");
		if (tmp->end)
			ft_putstr(tmp->end);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

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

int		num_c(char *s, int ch)
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

void	check_edge(t_val *head)
{
	t_val	*tmp;
	char	**av;

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

void	check_xy(t_val *head)
{
	t_val	*tmp;
	char	**av;

	if (!head)
		return ;
	if (!(tmp = head->next))
		return ;
	while (tmp->next)
	{
		av = ft_strsplit(tmp->line, ' ');
		if ((num_w(av) == 3 && av[0][0] != 'L') || !ft_strcmp
		(tmp->line, "##start") || !ft_strcmp(tmp->line, "##end"))
		{
			if (num_w(av) == 3 && check_realnum(av[1]) && check_realnum(av[2]))
				tmp->isxy = 1;
		}
		else
		{
			del_split(av);
			break ;
		}
		del_split(av);
		tmp = tmp->next;
	}
	check_edge(tmp);
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

void	split_name_xy(t_val *head)
{
	t_val	*tmp;
	char	**av;

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

t_val	*split_names(t_val **head)
{
	t_val	*tmp;
	char	**av;

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
			tmp->line = ft_strjoin_free(ft_strjoin(tmp->name1, "-"),
			tmp->name2, 1, 0);
			del_split(av);
		}
		tmp = tmp->next;
	}
	return (*head);
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

t_mod	*create_list_mod(t_const *con, t_val *map)
{
	t_mod *list;

	if (!(list = (t_mod*)malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	list->line = ft_strdup(map->line);
	list->weight = 1;
	if (!ft_strcmp(map->name2, con->start) || !ft_strcmp(map->name2, con->end))
	{
		list->name1 = ft_strdup(map->name2);
		list->name2 = ft_strdup(map->name1);
	}
	else
	{
		list->name1 = ft_strdup(map->name1);
		list->name2 = ft_strdup(map->name2);
	}
	list->c1 = 0;
	list->c2 = 0;
	list->loc = 0;
	list->ants = con->ants;
	list->start = ft_strdup(con->start);
	list->end = ft_strdup(con->end);
	return (list);
}

t_mod		*creator_mod(t_const *con, t_val *map, t_mod *head) //<-----------ошибки
{
	t_mod *tmp;

	tmp = head;

	while (head->next)
	{
		if (!ft_strcmp(map->line, head->line))
			return (tmp);
		head = head->next;
	}
	// 19 ошибок
	// if (map->line)
	// 	ft_putendl(head->line);
	// else
	// 	ft_putendl("пусто");
	if (!ft_strcmp(map->line, head->line))
		return (tmp);
	head->next = create_list_mod(con, map);
	return (tmp);
}

void	del_list_mod(t_mod **del)
{
	if (!(del))
		return ;
	free((*del)->line);
	free((*del)->name1);
	free((*del)->name2);
	free((*del)->start);
	free((*del)->end);
	free(*del);
}

void	del_roll_mod(t_mod **head)
{
	t_mod *tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_mod(head);
		*head = tmp;
	}
}

int		check_deadlock_add(t_mod *a, t_mod *b)
{
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	while (b)
	{
		if (a != b && a->ants && b->ants)
		{
			if (!ft_strcmp(a->name1, b->name1)
			|| !ft_strcmp(a->name1, b->name2))
				flag1 = 1;
			if (!ft_strcmp(a->name2, b->name1)
			|| !ft_strcmp(a->name2, b->name2))
				flag2 = 1;
		}
		b = b->next;
	}
	return (flag1 + flag2);
}

int		check_deadlock(t_mod *a, t_mod *b)
{
	t_mod		*tmp;
	int 	flag;

	flag = 0;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		if (ft_strcmp(a->start, a->name1) && ft_strcmp(a->start, a->name2)
		&& ft_strcmp(a->end, a->name1) && ft_strcmp(a->end, a->name2))
			if (check_deadlock_add(a, b) != 2)
			{
				a->ants = 0;
				flag = 1;
			}
		a = a->next;
	}
	return (flag == 0 ? FALSE : TRUE);
}

t_mod		*scrolling_mod(t_mod **h)
{
	t_mod *tmp;

	while ((*h))
	{
		if ((*h)->ants == 0)
		{
			tmp = (*h)->next;
			del_list_mod(h);
			*h = tmp;
		}
		else if ((*h)->ants != 0)
			break ;
		else
			*h = (*h)->next;
	}
	return (*h);
}

t_mod	*del_deadlock(t_mod **head)
{
	t_mod *tmp_prev;
	t_mod *h;

	h = scrolling_mod(head);
	while ((*head))
	{
		if ((*head)->ants == 0 && (*head)->next)
		{
			tmp_prev->next = (*head)->next;
			del_list_mod(head);
			(*head) = tmp_prev->next;
		}
		else if ((*head)->ants == 0 && !((*head)->next))
		{
			tmp_prev->next = NULL;
			del_list_mod(head);
			return (h);
		}
		else
		{
			tmp_prev = (*head);
			(*head) = (*head)->next;
		}
	}
	return (h);
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

int		check_deadlock_start_end_add(t_mod *a, t_mod *b)
{
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	while (b)
	{
		if (a != b && a->ants > 0 && b->ants > 0
		&& (!ft_strcmp(a->name1, a->start) || !ft_strcmp(a->name1, a->end)))
		{
			if (!ft_strcmp(a->name2, b->name1)
			|| !ft_strcmp(a->name2, b->name2))
				flag1 = 1;
		}
		if (a != b && a->ants > 0 && b->ants > 0
		&& (!ft_strcmp(a->name2, a->start) || !ft_strcmp(a->name2, a->end)))
		{
			if (!ft_strcmp(a->name1, b->name1)
			|| !ft_strcmp(a->name1, b->name2))
				flag2 = 1;
		}
		b = b->next;
	}
	return (flag1 + flag2);
}

int		check_deadlock_start_end(t_mod *a, t_mod *b)
{
	t_mod		*tmp;
	int		flag;

	flag = 0;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		if (!ft_strcmp(a->start, a->name1) || !ft_strcmp(a->start, a->name2)
		|| !ft_strcmp(a->end, a->name1) || !ft_strcmp(a->end, a->name2))
		{
			if (check_deadlock_start_end_add(a, b) != 1)
			{
				a->ants = 0;
				flag = 1;
			}
		}
		a = a->next;
	}
	if (flag == 0)
		return (FALSE);
	return (TRUE);
}

int		simple_solve(t_mod *h)
{
	while (h)
	{
		if (((!ft_strcmp(h->name2, h->start) || !ft_strcmp(h->name2, h->end))
		&& (!ft_strcmp(h->name1, h->start) || !ft_strcmp(h->name1, h->end))))
			return (TRUE);
		h = h->next;
	}
	return (FALSE);
}

void	print_simple_solve(t_mod *h)
{
	int i;

	i = 1;
	while (i <= h->ants)
	{
		ft_putchar('L');
		ft_putstr(ft_itoa(i));
		ft_putchar('-');
		ft_putstr(h->end);
		if (i != h->ants)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

// void	forward_list_add(t_mod **head)
// {
// 	char *tmp;
//
// 	tmp = (*head)->name1;
// 	if (!ft_strcmp((*head)->start, (*head)->name1))
// 		return ;
// 	else
// 	{
// 		(*head)->name1 = (*head)->name2;
// 		(*head)->name2 = tmp;
// 	}
// }

void	forward_list(t_mod **head, char *s)
{
	t_mod *tmp_prev;
	t_mod *oldh;
	t_mod *tmp;

	oldh = *head;
	while ((*head))
	{
		if (!ft_strcmp(s, (*head)->name1)
		|| !ft_strcmp(s, (*head)->name2))
		{
			tmp_prev->next = NULL;
			tmp = *head;
			(*head)->loc = 1;
			break ;
		}
		else
		{
			tmp_prev = (*head);
			(*head) = (*head)->next;
		}
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = oldh;
	//forward_list_add(head);
}

int		check_unlocal_add(t_mod *tmp)
{
	int flag;

	flag = 0;
	while (tmp)
	{
		if (tmp->loc != 1)
		{
			tmp->ants = 0;
			flag = 1;
		}
		tmp = tmp->next;
	}
	return (flag);
}

int		check_unlocal(t_mod *a, t_mod *b)
{
	t_mod	*tmp;
	int		flag;

	tmp = b;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		flag = 0;
		while (b)
		{
			if (a != b && b->loc != 1 && a->loc == 1 && (!ft_strcmp
			(a->name1, b->name1) || !ft_strcmp(a->name1, b->name2) ||
			!ft_strcmp(a->name2, b->name1) || !ft_strcmp(a->name2, b->name2)))
			{
				b->loc = 1;
				flag = 1;
			}
			b = b->next;
		}
		b = tmp;
		a = flag == 1 ? tmp : a;
		a = a->next;
	}
	return (check_unlocal_add(tmp));
}

void	vertex_start_end(t_mod *a)
{
	a->c1 = !ft_strcmp(a->name1, a->end) ? END : a->c1;
	a->c2 = !ft_strcmp(a->name2, a->end) ? END : a->c2;
	a->c1 = !ft_strcmp(a->name1, a->start) ? START : a->c1;
	a->c2 = !ft_strcmp(a->name2, a->start) ? START : a->c2;
}

int		cost_vertex_add(t_mod *a, t_mod *b)
{
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	if (!a || !b)
		return (FALSE);
	while (b)
	{
		count1 = (!ft_strcmp(a->name1, b->name1) || !ft_strcmp
		(a->name1, b->name2)) ? count1 + 1 : count1;
		count2 = (!ft_strcmp(a->name2, b->name1) || !ft_strcmp
		(a->name2, b->name2)) ? count2 + 1 : count2;
		b = b->next;
	}
	a->c1 = count1;
	a->c2 = count2;
	if (count1 == 2 || count2 == 2)
		return (TRUE);
	return (FALSE);
}

int		cost_vertex(t_mod *a, t_mod *b)
{
	int flag;

	flag = 0;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		if (cost_vertex_add(a, b))
			flag = 1;
		if (!ft_strcmp(a->name1, a->end) || !ft_strcmp(a->name2, a->end)
		|| !ft_strcmp(a->name1, a->start) || !ft_strcmp(a->name2, a->start))
			vertex_start_end(a);
		a = a->next;
	}
	if (flag == 1)
		return (TRUE);
	return (FALSE);
}

int		find_cheap_edge(t_mod *h, char *name)
{
	int min;

	min = h->c1 + h->c2;
	while (h)
	{
		if ((!ft_strcmp(h->name1, name) || !ft_strcmp(h->name2, name))
		&& h->ants)
			min = min > h->c1 + h->c2 ? h->c1 + h->c2 : min;
		h = h->next;
	}
	return (min);
}

void	devourer_add(t_mod *a, t_mod *b, int flag)
{
	while (b)
	{
		if (!ft_strcmp(flag == 1 ? a->name1 : a->name2, b->name1))
		{
			free(b->name1);
			b->name1 = flag == 1 ? ft_strdup(a->name2) : ft_strdup(a->name1);
			b->c1 = flag == 1 ? a->c2 : a->c1;
			b->weight += a->weight;
			b->line = ft_strjoin_free
			(ft_strjoin_free(b->line, "\n", 1, 0), a->line, 1, 0);
			break ;
		}
		if (!ft_strcmp(flag == 1 ? a->name1 : a->name2, b->name2))
		{
			free(b->name2);
			b->name2 = flag == 1 ? ft_strdup(a->name2) : ft_strdup(a->name1);
			b->c2 = flag == 1 ? a->c2 : a->c1;
			b->weight += a->weight;
			b->line = ft_strjoin_free
			(ft_strjoin_free(b->line, "\n", 1, 0), a->line, 1, 0);
			break ;
		}
		b = b->next;
	}
}

void	devourer(t_mod *h)
{
	while (h)
	{
		if (h->c1 == 2)
		{
			h->ants = 0;
			devourer_add(h, h->next, 1);
			break ;
		}
		else if (h->c2 == 2)
		{
			h->ants = 0;
			devourer_add(h, h->next, 2);
			break ;
		}
		h = h->next;
	}
}

int		check_cheap_vertex(t_mod *h)
{
	while (h)
	{
		if (h->ants != 0 && (h->c1 == 2 || h->c2 == 2))
			return (TRUE);
		h = h->next;
	}
	return (FALSE);
}

int		check_dubl_way_add(t_mod *a, t_mod *b)
{
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	while (b)
	{
		if (a != b && a->ants > 0 && b->ants > 0)
		{
			if (!ft_strcmp(a->name1, b->name1)
			|| !ft_strcmp(a->name1, b->name2))
				flag1 = 1;
			if (!ft_strcmp(a->name2, b->name1)
			|| !ft_strcmp(a->name2, b->name2))
				flag2 = 1;
		}
		b = b->next;
	}
	return (flag1 + flag2);
}

int		check_dubl_way(t_mod *a, t_mod *b)
{
	t_mod		*tmp;
	int 	flag;

	flag = 0;
	tmp = b;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		while (b)
		{
			if (a->weight > b->weight && b->ants != 0 && a != b && (!ft_strcmp
			(a->name1, b->name1) || !ft_strcmp(a->name1, b->name2)) &&
			(!ft_strcmp(a->name2, b->name1) || !ft_strcmp(a->name2, b->name2)))
			{
				a->ants = 0;
				flag = 1;
			}
			b = b->next;
		}
		b = tmp;
		a = a->next;
	}
	return (flag == 0 ? FALSE : TRUE);
}

t_mod		*create_list_mod_way(t_const *con, char *s)
{
	t_mod *list;
	char **arr;

	arr = ft_strsplit(s, '-');
	if (!(list = (t_mod*)malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	list->line = ft_strdup(s);
	list->weight = 1;
	list->name1 = ft_strdup(arr[0]);
	list->name2 = ft_strdup(arr[1]);
	list->c1 = 0;
	list->c2 = 0;
	list->loc = 0;
	list->ants = con->ants;
	list->start = ft_strdup(con->start);
	list->end = ft_strdup(con->end);
	del_split(arr);
	return (list);
}

t_mod		*creator_mod_way(t_const *con, char *s, t_mod *head) //<-----------ошибки
{
	t_mod *tmp;

	tmp = head;
	while (head->next)
	{
		head = head->next;
	}
	head->next = create_list_mod_way(con, s);
	return (tmp);
}

t_mod		*split_way(char *s, t_const *list)
{
	t_mod *head;
	char **arr;
	int i;

	i = 0;
	head = NULL;
	arr = ft_strsplit(s, '\n');
	while (arr[i])
	{
		if (!head)
			head = create_list_mod_way(list, arr[i]);
		else
			head = creator_mod_way(list, arr[i], head);
		i++;
	}
	del_split(arr);
	return (head);
}

int		len_list_mod(t_mod *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_way	*create_list_way(char *s, t_const *con, int len)
{
	t_way *list;

	if (!(list = (t_way*)malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	list->name = ft_strdup(s);
	list->len = len;
	list->ants = con->ants;
	list->ants_way = 0;
	list->num_ant = 0;
	list->start = ft_strdup(con->start);
	list->end = ft_strdup(con->end);
	return (list);
}

t_way	*build_way_head(t_mod *a, t_const *con)
{
	t_way *head;
	int len;

	head = NULL;
	len = len_list_mod(a);
	while (a)
	{
		if (!ft_strcmp(a->start, a->name1))
		{
			head = create_list_way(a->name2, con, len);
			a->ants = 0;
			break ;
		}
		if (!ft_strcmp(a->start, a->name2))
		{
			head = create_list_way(a->name1, con, len);
			a->ants = 0;
			break ;
		}
		a = a->next;
	}
	return (head);
}

t_way 	*creator_way(t_way *head, char *s, t_const *con)
{
	int len;
	t_way *tmp;

	len = head->len;
	tmp = head;
	while (head->next)
	{
		head = head->next;
	}
	head->next = create_list_way(s, con, len);
	return (tmp);
}

t_way	*scrolling_way(t_way *head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

t_way	*build_way(t_way *head, t_mod *a, t_const *con)
{
	t_mod *tmp;
	t_way *t;

	tmp = a;
	while (a)
	{
		t = scrolling_way(head);
		if (a->ants != 0 && !ft_strcmp((t)->name, a->name1))
		{
			(head) = creator_way((head), a->name2, con);
			a->ants = 0;
			a = tmp;
		}
		else if (a->ants != 0 && !ft_strcmp((t)->name, a->name2))
		{
			(head) = creator_way((head), a->name1, con);
			a->ants = 0;
			a = tmp;
		}
		else
			a = a->next;
	}
	return (head);
}

void 	del_list_way(t_way **del)
{
	if (!(del))
		return ;
	free((*del)->name);
	free((*del)->start);
	free((*del)->end);
	free(*del);
}

void	del_roll_way(t_way **head)
{
	t_way *tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_way(head);
		*head = tmp;
	}
}

int		len_hub(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	del_hub(char **hub)
{
	int i;

	i = 0;
	while (hub[i])
	{
		free(hub[i]);
		i++;
	}
}

void	del_tab(char *tab[START][START])
{
	int i;
	int j;

	i = 0;
	while (tab[i][0])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		i++;
	}
}

t_const	*create_list_const(void)
{
	t_const *list;

	if (!(list = (t_const*)malloc(sizeof(*list))))
		return (NULL);
	list->ants = 0;
	list->start = NULL;
	list->end = NULL;
	return (list);
}

void	del_list_const(t_const **list)
{
	free((*list)->start);
	free((*list)->end);
	free(*list);
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

void	printer_arr_way(t_way *arr[START])
{
	int i;

	i = 0;
	while (arr[i])
	{
		printer_way(arr[i]);
		i++;
	}
}

void 	del_arr_way(t_way *arr[START])
{
	int i;

	i = 0;
	while (arr[i])
	{
		del_roll_way(&arr[i]);
		i++;
	}
}

void	check_sum(t_way *arr[START], int max, int min)
{
	int i;
	int sum;

	sum = 0;
	i = -1;
	while (arr[++i])
	{
		sum += arr[i]->ants_way;
		max = max < arr[i]->len ? arr[i]->len : max;
		min = min > arr[i]->len ? arr[i]->len : min;
	}
	i = -1;
	while (arr[++i])
	{
		if (sum > arr[0]->ants && max == arr[i]->len)
		{
			arr[i]->ants_way--;
			break ;
		}
		if (sum < arr[0]->ants && min == arr[i]->len)
		{
			arr[i]->ants_way++;
			break ;
		}
	}
}

void	capacity(t_way *arr[START], int n)
{
	double	sum;
	int		i;
	int		rez;

	i = 0;
	sum = 0.0;
	rez = 0;
	while (i < n)
	{
		sum += ((double)1 / arr[i]->len);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		arr[i]->ants_way = (int)(((double)arr[i]->ants / arr[i]->len)
		/ sum + 0.5);
		i++;
	}
	check_sum(arr, 0, arr[0]->len);
}

int		check_ants_on_map(t_way *arr[START])
{
	int i;
	t_way *tmp;

	i = 0;
	while (arr[i])
	{
		tmp = arr[i];
		while (tmp)
		{
			if (tmp->ants_way != 0 || tmp->num_ant != 0)
				return (TRUE);
			tmp = tmp->next;
		}
		i++;
	}
	return (FALSE);
}

void	printer_ants(t_way *arr[START])
{
	int i;
	t_way *tmp;
	char *t;

	i = 0;
	while (arr[i])
	{
		tmp = arr[i];
		while (tmp)
		{
			if (tmp->num_ant != 0)
			{
				t = ft_itoa(tmp->num_ant);
				ft_putchar('L');
				ft_putstr(t);
				ft_putchar('-');
				ft_putstr(tmp->name);
				ft_putchar(' ');
				free(t);
			}
			tmp = tmp->next;
		}
		i++;
	}
	ft_putchar('\n');
}

void	tact(t_way *arr[START])
{
	int i;
	t_way *tmp;
	int t1;
	int t2;

	i = 0;
	while (arr[i])
	{
		tmp = arr[i];
		t1 = 0;
		t2 = 0;
		while (tmp)
		{
			t1 = tmp->num_ant;
			tmp->num_ant = t2;
			t2 = t1;
			tmp = tmp->next;
		}
		i++;
	}
}

void	horde_is_coming(t_way *arr[START])
{
	int num;
	int i;

	num = 1;
	while (check_ants_on_map(arr))
	{
		i = 0;
		while (arr[i] && num <= arr[i]->ants)
		{
			if (arr[i]->ants_way > 0)
			{
				arr[i]->num_ant = num;
				arr[i]->ants_way--;
				num++;
			}
			i++;
		}
		printer_ants(arr);
		tact(arr);
	}
}

int		check_distance(t_mod *h)
{
	while (h)
	{
		if (h->c1 == 0 || h->c2 == 0)
			return (TRUE);
		h = h->next;
	}
	return (FALSE);
}

int		check_end(t_mod *h)
{

	while (h)
	{
		if ((!ft_strcmp(h->name1, h->end) && h->c1 != 0) || (!ft_strcmp(h->name2, h->end) && h->c2 != 0))
			return (TRUE);
		h = h->next;
	}
	return (FALSE);
}

void	repeater(t_mod *h, char *from, int pred)
{
	while (h)
	{
		if (!ft_strcmp(h->name1, from) && (h->c1 == 0 || h->c1 > pred))
			h->c1 = pred;
		if (!ft_strcmp(h->name2, from) && (h->c2 == 0 || h->c2 > pred))
			h->c2 = pred;
		h = h->next;
	}
}

void	wave(t_mod *h, int pred)
{
	t_mod *tmp;

	tmp = h;
	while (h)
	{
		if (h->c1 == pred && (h->c2 == 0 || h->c2 > pred + 1))
		{
			h->c2 = pred + 1;
			repeater(tmp, h->name2, h->c2);
		}
		else if (h->c2 == pred && (h->c1 == 0 || h->c1 > pred + 1))
		{
			h->c1 = pred + 1;
			repeater(tmp, h->name1, h->c1);
		}
		h = h->next;
	}
}

void	wide_search(t_mod *h, t_mod *t, char *from, int pred)
{
	while (check_distance(h))
	{
		wave(h, pred);
		pred++;
	}
}

t_mod	*val_to_mod(t_const *list, t_val *map)
{
	t_mod	*head;

	head = NULL;
	while (map)
	{
		if (!head && ft_strcmp(map->name1, map->name2))
			head = create_list_mod(list, map);
		else if (head && ft_strcmp(map->name1, map->name2))
			head = creator_mod(list, map, head);
		map = map->next;
	}
	return (head);
}

int		check_long_way(t_mod *h, int end)
{
	int flag;

	flag = 0;
	while (h)
	{
		if ((h->c1 > end || h->c2 > end) || (h->c1 == end && h->c2 == end))
		{
			flag = 1;
			h->ants = 0;
		}
		h = h->next;
	}
	return (flag == 1 ? TRUE : FALSE);
}

int		length_short_way(t_mod *h)
{
	while (h)
	{
		if (!ft_strcmp(h->name1, h->end))
			return (h->c1);
		if (!ft_strcmp(h->name2, h->end))
			return (h->c2);
		h = h->next;
	}
	return (0);
}

void	search_from_end(t_mod *h, t_mod *t, char *from, char **way)
{
	if (!t)
		search_from_end(h, h, from, way);
	else if ((!ft_strcmp(t->name1, from) && !ft_strcmp(t->name2, t->start))
	|| (!ft_strcmp(t->name2, from) && !ft_strcmp(t->name1, t->start)))
	{
		joiner(t, way);
		return ;
	}
	else if (!ft_strcmp(t->name1, from))
	{
		joiner(t, way);
		return (search_from_end(h, t->next, t->name2, way));
	}
	else if (!ft_strcmp(t->name2, from))
	{
		joiner(t, way);
		return (search_from_end(h, t->next, t->name1, way));
	}
	else
		return (search_from_end(h, t->next, from, way));
}

t_way	*simple_search(t_const *list, t_val *map)
{
	t_way	*h;
	t_mod	*head;
	char	*way;

	head = val_to_mod(list, map);
	way = ft_strnew(0);
	killer_add(&head, list);
	head->c1 = 1;
	repeater(head, head->start, head->c1);
	wide_search((head), (head), (head)->name1, head->c1);
	if (check_long_way(head, length_short_way(head)))
		head = del_deadlock(&head);
	forward_list(&head, list->end);
	search_from_end(head, head, head->name1, &way);
	//printer_mod(head);
	del_roll_mod(&head);
	//ft_putendl(way);
	head = split_way(way, list);
	h = build_way_head(head, list);
	h = build_way(h, head, list);
	free(way);
	del_roll_mod(&head);
	return (h);
}

void	solution(char **s, t_const *list, t_val *old)
{
	t_mod	*head;
	int		i;
	t_way	*h;
	t_way	*arr[START];

	i = 0;
	// if (!s[1])
	// 	arr[0] = simple_search(list, old);//--????--ищем кратчайший путь тк он всего один
	// else
	// {
		while (s[i])
		{
			head = split_way(s[i], list);
			h = build_way_head(head, list);
			h = build_way(h, head, list);
			arr[i] = h;
			//printer_mod(head);
			del_roll_mod(&head);
			i++;
		}
	//}
	capacity(arr, i == 0 ? i + 1 : i);
	horde_is_coming(arr); //--------------------------------start
	//printer_arr_way(arr);
	del_arr_way(arr);
}

void	joiner(t_mod *t, char **way)
{
	t->ants = 0;
	*way = ft_strjoin_free(ft_strjoin_free(*way, "\n", 1, 0), t->line, 1, 0);
}

int		finder(t_mod *h, t_mod *t, char *from, char **way)
{
	int cost;

	//ft_putendl(from);
	cost = find_cheap_edge(h, from);
	if (!t)
		finder(h, h, from, way);
	else if ((!ft_strcmp(t->name1, from) && !ft_strcmp(t->name2, t->end))
	|| (!ft_strcmp(t->name2, from) && !ft_strcmp(t->name1, t->end)))
	{
		joiner(t, way);
		return (0);
	}
	else if (!ft_strcmp(t->name1, from) && cost == t->c1 + t->c2 && t->ants)
	{
		joiner(t, way);
		return (finder(h, t->next, t->name2, way));
	}
	else if (!ft_strcmp(t->name2, from) && cost == t->c1 + t->c2 && t->ants)
	{
		joiner(t, way);
		return (finder(h, t->next, t->name1, way));
	}
	else
		return (finder(h, t->next, from, way));
	return (0);
}

void 	separator(t_mod **head, int count, char **hub, t_const *list)
{
	char *way;

	way = ft_strnew(0);
	if ((*head)->c1 > (*head)->c2)
		finder((*head), (*head), (*head)->name1, &way);
	else
		finder((*head), (*head), (*head)->name2, &way);
	*head = del_deadlock(head);
	//ft_putendl(ft_itoa(count)); //утечка 4 б в итоа
	//ft_putendl(way);
	hub[count] = ft_strdup(way);
	free((void*)way);
	if ((*head))
		killer(head, count, hub, list);
}

void	killer_add(t_mod **head, t_const *list)
{
	while (check_deadlock(*head, *head))
		*head = del_deadlock(head);
	if (check_deadlock_start_end(*head, *head))
		*head = del_deadlock(head);
	if (ft_strcmp((*head)->start, (*head)->name1)
	&& ft_strcmp((*head)->start, (*head)->name2))
		forward_list(head, list->start);
	else
		(*head)->loc = 1;
	if (check_unlocal(*head, *head))
		*head = del_deadlock(head);
}

void	killer(t_mod **head, int count, char **hub, t_const *list)
{
	printer_mod(*head);
	ft_putendl("one");
	killer_add(head, list);
	//ft_putendl("two");
	while (cost_vertex(*head, *head))
	{
		while (check_cheap_vertex(*head))
		{
			devourer(*head);
			*head = del_deadlock(head);
		}
		if (check_dubl_way(*head, *head))
			*head = del_deadlock(head);
		else
			break ;
	}
	//ft_putendl("three");
	// printer_mod(*head);
	// ft_putendl("--");
	if ((*head))
		separator(head, count + 1, hub, list);
}

void	modify(t_const *list, t_val *map)
{
	t_mod *head;
	int count;
	char *hub[START];

	count = -1;
	ft_bzero(hub, START);
	if (!(map = scrolling_valid(map)))
		return ;
	//printer_valid(map);
	head = val_to_mod(list, map);
	if (simple_solve(head))
		print_simple_solve(head); //-------------- визуал для случая start-end
	else
		killer(&head, count, hub, list);//----- рекурсивно формируем хаб путей
	solution(hub, list, map);//---------------------расшифровка хаба путей в таблицу
	del_hub(hub);
	del_roll_mod(&head);
}

void	read_const(t_val *map)
{
	t_val	*h;
	t_const *list;

	h = map;
	if (!(list = create_list_const()))
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
	modify(list, h); //-------------------- читаем список t_val в список t_mod
	del_list_const(&list);
}

void	lemin(t_val **head)
{
	check_xy(*head);
	split_name_xy(*head);
	check_dupl_xy(*head, *head);
	check_commands(*head);
	check_dupl_start(*head);
	check_dupl_end(*head);
	*head = split_names(head);
	check_new_names(*head, *head);
	//printer_valid(*head);
	if (checker(*head))
		read_const(*head); //----------- читаем константы карты в лист t_const
	else
		ft_putendl("ERROR");
}

int		main(void) 	//---------------------------- читаем карту в список t_val
{
	t_val	*head;
	char	*arr;

	head = NULL;
	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		if (!head && not_comment(arr) && check_realnum(arr))
		{
			head = create_list_valid(arr);
			head->isnum = 1;
		}
		else if (head && not_comment(arr))
			head = creator_valid(head, arr);
		ft_memdel((void**)(&arr));
	}
	ft_memdel((void**)(&arr));
	if (!head)
		return (0);
	lemin(&head); //-------------------------------- проверяем валидность карты
	del_roll_valid(&head);
	return (0);
}
