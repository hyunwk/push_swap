/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:17:38 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 12:25:44 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	char	name;
	int		size;
	t_node	*first;
	t_node	*last;
}					t_list;

//basic_command.c
void		push_first(t_list *s, int val);
void		push_last(t_list *s, int val);
int			pop_first(t_list *s);
int			pop_last(t_list *s);
void		free_stack(t_list *s);
//command.c
void		swap(t_list *s);
void		push(t_list *a, t_list *b);
void		rotate(t_list *s);
void		reverse_rotate(t_list *s);
void		error(void);
//sort.c
void		sort(t_list *a, t_list *b);
void		sort_three(t_list *a);
void		sort_five(t_list *a, t_list *b);
int			is_sorted(t_list *s);
t_list		*simplify(t_list *s);
//main.c
t_node		*make_node(int val);
t_list		**init_list(t_list **s, char c);
void		is_valid_num(long long num, t_node *node);
t_list		*check_argv(t_list **a, char **s);
// ft_split.c
char		**ft_split(char const *s, char c);
char		*alloc_str(char	const *s, char c, int *idx);
int			get_len(char const *s, char set, int *i);
char		**freeall(char **s);
//ft_atoi.c
long long	ft_atoi(char *str);
//ft_putchar.c
void		ft_putchar(char c);
#endif
