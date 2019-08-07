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
	char			*name1;
	char			*name2;
	int				c1;
	int				c2;
	int				grey;
	int				loc;
	int				ants;
	char			*start;
	char			*end;
}					t_l;
void				del_list_valid(t_lst **del);
#endif
