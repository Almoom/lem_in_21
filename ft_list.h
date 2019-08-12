/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:14:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/06/19 14:14:22 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define TRUE 1
# define FALSE 0
# define END -1000
# define START 1000

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*line;
	char			*name;
	char			*x_y;
	char			*name1;
	char			*name2;
	int				isnum;
	int				isstart;
	int				isend;
	int				isxy;
	int				isedge;
}					t_lst;

typedef struct		s_l
{
	struct s_l		*next;
	char			*line;
	int				weight;
	char			*name1;
	char			*name2;
	int				c1;
	int				c2;
	int				loc;
	int				ants;
	char			*start;
	char			*end;
}					t_l;

typedef struct		s_const
{
	int				ants;
	char			*start;
	char			*end;
}					t_const;

typedef struct		s_way
{
	struct s_way	*next;
	char			*name;
	int				len;
	int				ants;
	char			*start;
	char			*end;
}					t_way;
void				del_list_valid(t_lst **del);
void				killer(t_l **head, int count, char **hub, t_const *list);
void				del_hub(char **hub);
#endif
