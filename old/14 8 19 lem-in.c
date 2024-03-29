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
	ft_putendl("line\tw\tname1\tc1\tname2\tc2\tloc\tants\tstart\tend\n");
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

t_mod		*create_list_mod(t_const *con, t_val *map)
{
	t_mod *list;

	if (!(list = (t_mod*)malloc(sizeof(*list))))
		return (NULL);
	list->next = NULL;
	list->line = ft_strdup(map->line);
	list->weight = 1;
	list->name1 = ft_strdup(map->name1);
	list->name2 = ft_strdup(map->name2);
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

void 	start_forward_list(t_mod **head)
{
	t_mod *tmp_prev;
	t_mod *oldh;
	t_mod *tmp;

	oldh = *head;
	while ((*head))
	{
		if (!ft_strcmp((*head)->start, (*head)->name1)
		|| !ft_strcmp((*head)->start, (*head)->name2))
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
	t_mod		*tmp;

	tmp = b;
	if (!a || !b)
		return (FALSE);
	while (a)
	{
		while (b)
		{
			if (a != b && b->loc != 1 && a->loc == 1 && (!ft_strcmp
			(a->name1, b->name1) || !ft_strcmp(a->name1, b->name2) ||
			!ft_strcmp(a->name2, b->name1) || !ft_strcmp(a->name2, b->name2)))
				b->loc = 1;
			b = b->next;
		}
		b = tmp;
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

void	joiner(t_mod *t, char **way)
{
	t->ants = 0;
	*way = ft_strjoin_free(ft_strjoin_free(*way, "\n", 1, 0), t->line, 1, 0);
}

int		finder(t_mod *h, t_mod *t, char *from, char **way)
{
	int cost;

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

void	killer(t_mod **head, int count, char **hub, t_const *list)
{
	while (check_deadlock(*head, *head))
		*head = del_deadlock(head);
	if (check_deadlock_start_end(*head, *head))
		*head = del_deadlock(head);
	if (ft_strcmp((*head)->start, (*head)->name1)
	&& ft_strcmp((*head)->start, (*head)->name2))
		start_forward_list(head);
	else
		(*head)->loc = 1;
	if (check_unlocal(*head, *head))
		*head = del_deadlock(head);
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
	if ((*head))
		separator(head, count + 1, hub, list);
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

int		len_list_way(t_way *head)
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

void	build_tab(char **tab, t_way *h)
{
	int i;
	int step;

	i = 0;
	step = len_list_way(h);
	while (h)
	{
		if (i == 0)
			tab[i] = ft_itoa(step);
		else
		{
			tab[i] = ft_strdup(h->name);
			h = h->next;
		}
		i++;
	}
	tab[i] = NULL;
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

// void	check_sum(char *tab[START][START], int ants)
// {
// 	int max;
// 	int i;
// 	int sum;
// 	char *tmp;
//
// 	max = 0;
// 	i = -1;
// 	while (tab[++i][0])
// 	{
// 		sum += ft_atoi(tab[i][0]);
// 		max = max < ft_atoi(tab[i][0]) ? ft_atoi(tab[i][0]) : max;
// 	}
// 	i = -1;
// 	if (sum > ants)
// 		while (tab[++i][0])
// 		{
// 			if (max == ft_atoi(tab[i][0]))
// 			{
// 				free(tab[i][0]);
// 				tmp = ft_itoa(max - 1);
// 				tab[i][0] = ft_strdup(tmp);
// 				free(tmp);
// 				break ;
// 			}
// 		}
// }

// void	capacity(char *tab[START][START], int ants)
// {
// 	double	sum;
// 	int		i;
// 	int		rez;
// 	char	*tmp;
//
// 	i = 0;
// 	sum = 0.0;
// 	rez = 0;
// 	while (tab[i][0])
// 	{
// 		sum += ((double)1 / ft_atoi(tab[i][0]));
// 		i++;
// 	}
// 	i = 0;
// 	while (tab[i][0])
// 	{
// 		rez = (int)(((double)ants / ft_atoi(tab[i][0])) / sum + 0.5);
// 		tmp = ft_itoa(rez);
// 		free(tab[i][0]);
// 		tab[i][0] = ft_strdup(tmp);
// 		free(tmp);
// 		i++;
// 	}
// 	check_sum(tab, ants);
// }

void	printer_tab(char *tab[START][START])
{
	int i;
	int j;

	i = 0;
	while (tab[i][0])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putendl(tab[i][j]);
			j++;
		}
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

t_ant	*create_list_ant(int num, t_const *con)
{
	t_ant *list;
	char *tmp;

	if (!(list = (t_ant*)malloc(sizeof(*list))))
		return (NULL);
	tmp = ft_itoa(num + 1);
	list->next = NULL;
	list->name = ft_strjoin_free("L", tmp, 0, 1);
	list->atstart = con->ants;
	list->in = 0;
	list->out = 0;
	list->end = ft_strdup(con->end);
	return (list);
}

t_ant	*creator_ants(int num, t_const *con, t_ant *head)
{
	t_ant *tmp;

	tmp = head;
	while (head->next)
	{
		head = head->next;
	}
	head->next = create_list_ant(num, con);
	return (tmp);
}

void	printer_ants(t_ant *head)
{
	t_ant *tmp;

	tmp = head;
	if (!tmp)
	{
		ft_putendl("(пусто)");
		return ;
	}
	ft_putendl("name\tatstart\tin\tout\tend\n");
	while (tmp)
	{
		if (tmp->name)
			ft_putstr(tmp->name);
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->atstart));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->in));
		ft_putstr("\t");
		ft_putstr(ft_itoa(tmp->out));
		ft_putstr("\t");
		if (tmp->end)
			ft_putstr(tmp->end);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	del_list_ant(t_ant **del)
{
	ft_memdel((void**)(&(*del)->name));
	ft_memdel((void**)(&(*del)->end));
	free(*del);
}

void	del_ants(t_ant **head)
{
	t_ant *tmp;

	if (!(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		del_list_ant(head);
		*head = tmp;
	}
}

int		check_ants_on_map(t_ant *head)
{
	while (head)
	{
		if (head->in == 0 || head->out == 0)
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

void 	printer_tact(t_ant *head, char *room)
{
	ft_putstr(head->name);
	ft_putchar('-');
	ft_putstr(room);
	if (head->next && head->next->out != 1)
		ft_putchar(' ');
}

void	decrement_ants_for_way(char *s)
{
	int n;

	n = ft_atoi(s);
	if (n > 0)
	{
		n--;
		free(s);
		s = ft_itoa(n);
	}
}

void	visualization(char *tab[START][START], t_ant *head)
{
	int i;
	int j;
	t_ant *tmp;

	i = 0;
	j = 1;
	tmp = head;
	if (check_ants_on_map(head))
	{
		while (tab[i][0] && head)
		{
			decrement_ants_for_way(tab[i][0]);
			printer_tact(head, tab[i][j]);
			head->in = 1;
			head = head->next;
			i++;
		}
		ft_putchar('\n');
		//printer_ants(tmp);
		//printer_tab(tab);
		visualization(tab, head);
	}
	head = tmp;
	j++;
	i = 0;
	if (check_ants_on_map(head))
	{
		while (tab[i][0] && head)
		{
			decrement_ants_for_way(tab[i][0]);
			printer_tact(head, tab[i][j]);
			head->in = 1;
			head = head->next;
			i++;
		}
		ft_putchar('\n');
		//printer_ants(tmp);
		//printer_tab(tab);
		visualization(tab, head);
	}
}

void	deity(char *tab[START][START], t_const *con)
{
	t_ant *head;
	int i;

	i = 0;
	head = NULL;
	while (i < con->ants)
	{
		if (!head)
			head = create_list_ant(i, con);
		else
			head = creator_ants(i, con, head);
		i++;
	}
	visualization(tab, head);
	del_ants(&head);
}

// void	zero_tab(char *tab[START][START])
// {
// 	int i;
// 	int j;
//
// 	i = 0;
// 	while (i < START)
// 	{
// 		j = 0;
// 		while (j < START)
// 		{
// 			tab[i][j] = NULL;
// 			j++;
// 		}
// 		i++;
// 	}
// }
//
// void 	otsechka(char *(*tab)[START])
// {
// 	int i;
//
// 	i = 0;
//
// 	while (i < START)
// 	{
// 		*tab[i] = NULL;
// 		i++;
// 	}
// 	ft_putendl("--");
// }
//
// char	***malloc_bzero_tab(int x, int y)
// {
// 	char ***tab;
// 	int i;
// 	int j;
//
// 	i = 0;
// 	if (!(tab = (char***)malloc(sizeof(**tab) * (x + 1))))
// 		return (NULL);
// 	while (i < x)
// 	{
// 		if (!(tab[i] = (char**)malloc(sizeof(*tab) * (y + 1))))
// 			return (NULL);
// 		j = 0;
// 		while (j < y)
// 		{
// 			if (!(tab[i][j] = (char*)malloc(sizeof(*tab))))
// 				return (NULL);
// 			ft_bzero(tab[i][j], sizeof(*tab));
// 			j++;
// 		}
// 		tab[i][j] = 0;
// 		i++;
// 	}
// 	tab[i] = 0;
// 	return (tab);
// }

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

void	capacity(t_way *arr[START])
{
	double	sum;
	int		i;
	int		rez;

	i = 0;
	sum = 0.0;
	rez = 0;
	while (arr[i])
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

void	solution(char **s, t_const *list)
{
	t_mod	*head;
	//char	*tab[START][START];
	int		i;
	t_way	*h;
	t_way	*arr[START];

	i = 0;
	//zero_tab(tab);
	while (s[i])
	{
		head = split_way(s[i], list);
		h = build_way_head(head, list);
		h = build_way(h, head, list);
		arr[i] = h;
		//build_tab(tab[i], h);
		//printer_mod(head);
		del_roll_mod(&head);
		i++;
	}
	capacity(arr);
	printer_arr_way(arr);
	del_arr_way(arr);
	//otsechka(&tab[i]);
	//capacity(tab, list->ants);
	//deity(tab, list); //----------------------------создаем список муравьев
	//printer_tab(tab);
	//del_tab(tab);
}

void	modify(t_const *list, t_val *map)
{
	t_mod *head;
	int count;
	char *hub[START];

	head = NULL;
	count = -1;
	ft_bzero(hub, START);
	if (!(map = scrolling_valid(map)))
		return ;
	while (map)
	{
		if (!head && ft_strcmp(map->name1, map->name2))
			head = create_list_mod(list, map);
		else if (head && ft_strcmp(map->name1, map->name2))
			head = creator_mod(list, map, head);
		map = map->next;
	}
	if (simple_solve(head))
		print_simple_solve(head); //-------------- визуал для случая start-end
	else
		killer(&head, count, hub, list); //----- рекурсивно формируем хаб путей
	solution(hub, list);//---------------------расшифровка хаба путей в таблицу
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
