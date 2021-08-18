/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_two_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/18 16:33:10 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

typedef struct s_node
{
	int data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_deq
{
	t_node	*first;
	t_node	*last;
}					t_deq;

t_node *make_node(int val)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		ft_putstr("malloc error.\n");
		exit(1);
	}
	node->data = val;
	node->prev = 0;
	node->next = 0;
	return (node);
}

void init_deq(t_deq **a, t_deq **b)
{
	*a = (t_deq *)malloc(sizeof(t_deq));
	*b = (t_deq *)malloc(sizeof(t_deq));
	if ((*a) == 0)
	{
		ft_putstr("malloc error.\n");
		exit(1);
	}
	if ((*b) == 0)
	{
		free(a);
		ft_putstr("malloc error.\n");
		exit(1);
	}
	(*a)->first = 0;
	(*a)->last= 0;
	(*b)->first = 0;
	(*b)->last = 0;
}

void push_first(t_deq *s, int val)
{
	t_node *new;
	
	new = make_node(val);
	if (!(s->first))
	{
		s->first = new;
		s->first->next = s->last;
		s->first->prev = s->last;
		s->last = new;
		s->last->next = s->first;
		s->last->prev= s->first;
		return ;
	}
	s->first->prev = new;
	s->last->next = new;
	new->prev = s->last;
	new->next= s->first;
	s->first = new;
}

void push_last(t_deq *s, int val)
{
	t_node *new;
	
	new = make_node(val);
	if (!(s->last))
	{
		s->first = new;
		s->first->next = s->last;
		s->first->prev = s->last;
		s->last = new;
		s->last->next = s->first;
		s->last->prev= s->first;
		return ;
	}
	s->last->next = new;
	s->first->prev = new;
	new->prev = s->last;
	new->next= s->first;
	s->last = new;
}

int		pop_first(t_deq *s)
{
	t_node *origin_first;
	int		removed_data;

	if (s->first== 0)
	{
		ft_putstr("remove error");
		return (0);
	}
	if (s->first == s->last)
	{
		s->first = 0;
		s->last = 0;
	}
	else
	{
		origin_first = s->first;
		s->last->next = origin_first->next;
		s->last = origin_first->prev;
		s->first->prev = origin_first->prev;
	}
	removed_data = origin_first->data;
	free(origin_first);
	return (removed_data);
}
int		pop_last(t_deq *s)
{
	t_node *origin_last;
	int		removed_data;

	if (s->last == 0)
	{
		ft_putstr("remove error");
		return (0);
	}
	if (s->first == s->last)
	{
		s->first = 0;
		s->last = 0;
	}
	else
	{
		origin_last = s->last;
		s->last->prev->next = origin_last->next;
		s->first->prev = origin_last->prev;
		s->last = origin_last->prev;
	}
	removed_data = origin_last->data;
	free(origin_last);
	return (removed_data);
}

void swap(t_deq *s)
{
	t_node *temp;
	int		data_last;
	int		data_last_prev;
	//	s the first 2 elements at the top of stack
	//	1. 아무것도 없을 경우
	if (!(s->first))
		return ;
	// 2. data 하나 있을 경우
	if (s->first == s->first->next)
		return ;
	// 3. data 2개 있을 경우
	if (s->first->next == s->last)
	{
		temp = s->first;
		s->first = s->last;
		s->last = temp;
		return ;
	}
	// 4. data 3개 이상
	data_last = pop_last(s);
	data_last_prev = pop_last(s);
	push_last(s, data_last);
	push_last(s, data_last_prev);
}

void push(t_deq *a, t_deq *b)
{
	push_last(b, pop_last(a));
}

void rotate(t_deq *s)
{
}

#include<stdio.h>
int main()
{
	t_deq *a;
	t_deq *b;

	init_deq(&a, &b);
	push_last(a, 1);
	push_last(a, 2);
	push_last(a, 3);
	printf("a->first %d\n", a->first->data);
	printf("a->first->prev %d\n", a->first->prev->data);
	printf("a->first->next %d\n", a->first->next->data);
	printf("a->last %d\n", a->last->data);
	printf("a->last->prev %d\n", a->last->prev->data);
	printf("a->last->next%d\n", a->last->next->data);
	swap(a);
	printf("======after swap a\n");
	printf("a->first %d\n", a->first->data);
	printf("a->first->prev %d\n", a->first->prev->data);
	printf("a->first->next %d\n", a->first->next->data);
	printf("a->last %d\n", a->last->data);
	printf("a->last->prev %d\n", a->last->prev->data);
	printf("a->last->next%d\n", a->last->next->data);
	push(a, b);
	printf("======after push\na\n");
	printf("a->first %d\n", a->first->data);
	printf("a->first->prev %d\n", a->first->prev->data);
	printf("a->first->next %d\n", a->first->next->data);
	printf("a->last %d\n", a->last->data);
	printf("a->last->prev %d\n", a->last->prev->data);
	printf("a->last->next%d\n", a->last->next->data);
	printf("b\n");
	printf("b->first %d\n", b->first->data);
	printf("b->first->prev %d\n", b->first->prev->data);
	printf("b->first->next %d\n", b->first->next->data);
	printf("b->last %d\n", b->last->data);
	printf("b->last->prev %d\n", b->last->prev->data);
	printf("b->last->next%d\n", b->last->next->data);

}
