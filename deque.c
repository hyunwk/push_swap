/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:48:38 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/17 14:12:33 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
typedef struct s_deq
{
	int				data;
	struct s_deq	*prev;
	struct s_deq	*next;
}					t_deq;

t_deq *make_node(int val);
void add_last(t_deq **first, t_deq **last, int val);
void add_first(t_deq **first, t_deq **last, int val);
void remove_first(t_deq **first, t_deq **last);
void remove_last(t_deq **first, t_deq **last);
void swap(t_deq **first, t_deq **last);
void push(t_deq **first, t_deq **last, int val);
void rotate(t_deq **first, t_deq **last);
void reverse_rotate(t_deq **first, t_deq **last);


t_deq *make_node(int val)
{
	t_deq *node;

	node = (t_deq*)malloc(sizeof(t_deq));
	node->data = val;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void add_first(t_deq **first, t_deq **last, int val)
{
	t_deq	*new;

	new = make_node(val);
	if (*first == NULL && *last == NULL)
	{
		*first = new;
		*last = new;
	}
	else 
	{
		new->next = *first;
		(*first)->prev = new;
		*first = new;
		(*last)->next = *first;
		(*first)->prev = *last;
	}
}
void add_last(t_deq **first, t_deq **last, int val)
{
	t_deq	*new;

	new = make_node(val);
	if (*first == NULL && *last == NULL)
	{
		*first = new;
		*last = new;
	}
	else 
	{
		new->prev = *last;
		(*last)->next = new;
		*last = new;
		(*last)->next = *first;
		(*first)->prev = *last;
	}
}
void remove_last(t_deq **first, t_deq **last)
{
	t_deq *origin_last;

	if (*first == 0 || *last == 0)
	{
		ft_putstr("remove error");
		return ;
	}
	if (*first == *last)
	{
		*first = 0;
		*last = 0;
	}
	else 
	{
		origin_last = *last;
		(*last)->prev->next = origin_last->next;
		(*first)->prev = origin_last->prev;
		*last = origin_last->prev;
	}
	free(origin_last);
}

void remove_first(t_deq **first, t_deq **last)
{
	t_deq *origin_first;

	if (*first == 0 || *last == 0)
	{
		ft_putstr("remove error");
		return ;
	}
	if (*first == *last)
	{
		*first = 0;
		*last = 0;
	}
	else 
	{
		origin_first = *first;
		(*first)->next->prev = origin_first->prev;
		(*last)->next = origin_first->next;
		*first = origin_first->next;
	}
	free(origin_first);
}

#include<stdio.h>
int main()
{
	t_deq *first;
	t_deq *last;

	first = 0;
	last = 0;
//	first = make_node(2);
//	last = first;
	//add_last(deq, 3);
	add_last(&first, &last, 1);
	add_last(&first, &last, 2);
	add_last(&first, &last, 3);
	add_last(&first, &last, 4);
	printf("first->prev %d\n", first->prev->data);
	printf("first %d\n", first->data);
	printf("first->next %d\n", first->next->data);
	printf("last->prev %d\n", last->prev->data);
	printf("last %d\n", last->data);
	printf("last next %d\n", last->next->data);
	remove_last(&first, &last);
	printf("after remove last\n");
	printf("first->prev %d\n", first->prev->data);
	printf("first %d\n", first->data);
	printf("first->next %d\n", first->next->data);
	printf("last->prev %d\n", last->prev->data);
	printf("last %d\n", last->data);
	printf("last next %d\n", last->next->data);
}
