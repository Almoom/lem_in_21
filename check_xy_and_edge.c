/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xy_and_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:04:53 by ljalikak          #+#    #+#             */
/*   Updated: 2019/08/18 14:04:55 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
		if (!ft_strcmp(tmp->line, "##start") || !ft_strcmp(tmp->line, "##end")
		|| (num_w(av) == 3 && av[0][0] != 'L'))
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

int		num_w(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
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
