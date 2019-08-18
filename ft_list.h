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

typedef struct		s_val
{
	struct s_val	*next;
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
}					t_val;

typedef struct		s_mod
{
	struct s_mod		*next;
	char			*line;
	int				weight;
	char			*name1;
	char			*name2;
	int				c1;
	int				c2;
	int				loc;
	int				loop;
	int				ants;
	char			*start;
	char			*end;
}					t_mod;

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
	int				ants_way;
	int				num_ant;
	char			*start;
	char			*end;
}					t_way;

// typedef struct		s_ant
// {
// 	struct s_ant	*next;
// 	char			*name;
// 	int				atstart;
// 	int				in;
// 	int				out;
// 	char			*end;
// }					t_ant;

/*
**	main.c
*/

int		main(void);
void	lemin(t_val **head);
int		checker(t_val *head);
void	check_commands(t_val *head);
void	check_new_names(t_val *a, t_val *b);

/*
**	list_val.c
*/

t_val	*create_list_valid(char *s);
t_val	*creator_valid(t_val *head, char *s);
void	printer_valid(t_val *head);
void	del_list_valid(t_val **del);
void	del_roll_valid(t_val **head);

/*
**	check_comment_and_realnum.c
*/

int		not_comment(char *s);
int		check_realnum(char *s);
int		check_realnum_add(char *s, int n, int len);

/*
**	check_xy_and_edge.c
*/

void	check_xy(t_val *head);
void	check_edge(t_val *head);
int		num_w(char **av);
int		num_c(char *s, int ch);

/*
**	splits.c
*/

void	split_name_xy(t_val *head);
t_val	*split_names(t_val **head);
void	del_split(char **s);

/*
**	duplicate.c
*/

void	check_dupl_xy(t_val *a, t_val *b);
void	check_dupl_start(t_val *head);
void	check_dupl_end(t_val *head);

/*
**	list_const.c
*/

void	read_const(t_val *map);
t_const	*create_list_const(int ants, char *start, char *end);
void	del_list_const(t_const **list);
t_val	*scrolling_valid(t_val *map);



void	printer_mod(t_mod *head);
void	printer_way(t_way *head);
t_mod	*create_list_mod(t_const *con, t_val *map);
t_mod	*creator_mod(t_const *con, t_val *map, t_mod *head);
void	del_list_mod(t_mod **del);
void	del_roll_mod(t_mod **head);
int		check_deadlock_add(t_mod *a, t_mod *b);
int		check_deadlock(t_mod *a, t_mod *b);
t_mod	*scrolling_mod(t_mod **h);
t_mod	*del_deadlock(t_mod **head);
int		check_deadlock_start_end_add(t_mod *a, t_mod *b);
int		check_deadlock_start_end(t_mod *a, t_mod *b);
int		simple_solve(t_mod *h);
void	print_simple_solve(t_mod *h);
void	forward_list(t_mod **head, char *s);
int		check_unlocal_add(t_mod *tmp);
int		check_unlocal(t_mod *a, t_mod *b);
void	vertex_start_end(t_mod *a);
int		cost_vertex_add(t_mod *a, t_mod *b);
int		cost_vertex(t_mod *a, t_mod *b);
void	devourer_add(t_mod *a, t_mod *b, int flag);
void	devourer(t_mod *h);
int		check_cheap_vertex(t_mod *h);
int		check_dubl_way_add(t_mod *a, t_mod *b);
int		check_dubl_way(t_mod *a, t_mod *b);
t_mod	*create_list_mod_way(t_const *con, char *s);
t_mod	*creator_mod_way(t_const *con, char *s, t_mod *head);
t_mod	*split_way(char *s, t_const *list);
int		len_list_mod(t_mod *head);
t_way	*create_list_way(char *s, t_const *con, int len);
t_way	*build_way_head(t_mod *a, t_const *con);
t_way 	*creator_way(t_way *head, char *s, t_const *con);
t_way	*scrolling_way(t_way *head);
t_way	*build_way(t_way *head, t_mod *a, t_const *con);
void 	del_list_way(t_way **del);
void	del_roll_way(t_way **head);
int		len_hub(char **s);
void	del_hub(char **hub);
void	del_tab(char *tab[START][START]);
void	printer_arr_way(t_way *arr[START]);
void	del_arr_way(t_way *arr[START]);
void	check_sum(t_way *arr[START], int max, int min);
void	capacity(t_way *arr[START], int n);
int		check_ants_on_map(t_way *arr[START]);
void	printer_ants(t_way *arr[START]);
void	tact(t_way *arr[START]);
void	horde_is_coming(t_way *arr[START]);
int		check_distance(t_mod *h);
int		check_end(t_mod *h);
void	repeater(t_mod *h, char *from, int pred);
void	wave(t_mod *h, int pred);
void	wide_search(t_mod *h, t_mod *t, char *from, int pred);
t_mod	*val_to_mod(t_const *list, t_val *map);
int		check_long_way(t_mod *h, int end);
int		length_short_way(t_mod *h);
void	search_from_end(t_mod *h, t_mod *t, char *from, char **way);
t_way	*simple_search(t_const *list, t_val *map);
void	solution(char **s, t_const *list, t_val *old);
void	joiner(t_mod *t, char **way);
int		find_cheap_edge(t_mod *h, char *from);
int		numbers_ants(t_mod *h);
void	recovery_index(t_mod *h, int ants);
void	find_ring(t_mod *a, t_mod *b);
void	marker_ring(t_mod *h);
int		check_valid_start_end(t_mod *h);
void	kill_loop(t_mod **h);
int		check_way(t_mod *h);
int		finder(t_mod **h, t_mod *t, char *from, char **way);
void	separator(t_mod **head, int count, char **hub, t_const *list);
void	recovery_index_start_end(t_mod *h, t_const *list);
void	killer_add(t_mod **head, t_const *list);
void	killer(t_mod **head, int count, char **hub, t_const *list);
void	modify(t_const *list, t_val *map);
#endif
