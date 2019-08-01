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
	while ((*head)->next)
	{
		tmp = (*head)->next;
		ft_memdel((void**)(&(*head)->line));
		ft_memdel((void**)(&(*head)->name));
		free(*head);
		*head = tmp;
	}
	ft_memdel((void**)(&(*head)->line));
	free(*head);
}

int		check_void(t_lst *head)
{
	t_lst *tmp;

	tmp = head;
	if (!head)
		return (FALSE);
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->line, ""))
			return (FALSE);
		tmp = tmp->next;
	}
	if (!ft_strcmp(tmp->line, ""))
		return (FALSE);
	return (TRUE);
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
			if (num_w(av) == 3 && check_realnum(av[1]) && check_realnum(av[2]))
				tmp->isxy = 1;
		}
		else
		{
			del_split(av);
			break;
		}
		del_split(av);
		tmp = tmp->next;
	}
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

void	name_knot(t_lst *head)
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
			del_split(av);
		}
		tmp = tmp->next;
	}
}

void	check_dupl(t_lst *heada, t_lst *headb)
{
	t_lst *tmp;

	tmp = headb;
	if (!heada || !headb)
		return ;
	while (heada->next)
	{
		printf("%s\n", "-");
		while (headb->next)
		{
			printf("%s\n", "--");
			if (heada->name && headb->name && !ft_strcmp(heada->name, headb->name))
			{
				printf("%s__%s\n", heada->name, headb->name);
				//tmp->isxy = 0;
			}

			headb = headb->next;
		}
		headb = tmp;
		heada = heada->next;
	}
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
	check_xy(head);
	name_knot(head);
	check_dupl(head, head);
	check_commands(head);
	if (check_void(head))
		printer(head);
	else
		ft_putendl("ERROR");
	del_roll(&head);
	return (0);
}
