/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_value_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/20 20:13:11 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

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

void init_deq(t_deq **s)
{
	*s = (t_deq *)malloc(sizeof(t_deq));
	if ((*s) == 0)
	{
		ft_putstr("malloc error.\n");
		exit(1);
	}
	(*s)->first = 0;
	(*s)->last= 0;
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
		s->last->next = s->first->next;
		s->first->next->prev = s->last;
		s->first= s->first->next;
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
	int		data;
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
//	if (s->first->next == s->last)
//	{
//		temp = s->first;
//		s->first = s->last;
//		s->last = temp;
//		return ;
//	}
	// 4. data 3개 이상

	data = s->last->data;
	s->last->data = s->last->prev->data;
	s->last->prev->data = data;
//	data_last = pop_last(s);
//	data_last_prev = pop_last(s);
//	push_last(s, data_last);
//	push_last(s, data_last_prev);
}

int get_stack_len(t_deq *s)
{
	int len;
	t_node *node;

	len = 0;
	node = s->first;
	while (node)
	{
		node = node->next;
		len++;
		if (node == s->first)
			return (len);
	}
	return (0);
}

void push(t_deq *a, t_deq *b)
{
	push_last(b, pop_last(a));
}

void rotate(t_deq *s)
{
	push_last(s, pop_first(s));
}

void reverse_rotate(t_deq *s)
{
	push_first(s, pop_last(s));
}

#include<stdio.h>

void print_all(t_deq *s, t_deq *s2)
{
	t_node *node;
	t_node *node_2;
	int		len;
	int		len_1;
	int		len_2;
	int		i;
	int		j;
	int		k;

	len_1 = get_stack_len(s);
	len_2 = get_stack_len(s2);
	if (len_1 > len_2)
	{
		k = len_1 - len_2;
		len = len_1;
	}
	else
	{
		k = len_2 - len_1;
		len = len_2;
	}
	i = 0;
	node = s->last;
	node_2 = s2->last;
	printf("----------------------------\n");
	while (i < len)
	{
		j = 7;
		if (len_1 > len_2 || !k)
		{

			printf("%d : ",node->data);
			while (j != -1)
			{
				printf("%d",node->data >> j & 1);
				j--;
			}
			node = node->prev;
		}
		printf("    ");
		j = 7;
		if (len_2 > len_1 || !k)
		{
			printf("%d : ",node_2->data);
			while (j != -1)
			{
				printf("%d",node_2->data >> j & 1);
				j--;
			}
			node = node->prev;
		}
		k--;
		printf("\n");
		i++;
	}
	printf("----------------------------\n");
	printf("        a               b  "); 
}

t_deq *simplify(t_deq *s)
{
	t_deq *stack;
	t_node *i;
	t_node *j;
	int temp;

	init_deq(&stack);
	i = s->first;
	while (i)
	{
		j = s->first;
		temp = 0;
		while (j)
		{
			if (j->data > i->data)
				temp += 1;
			j = j->next;
			if (j == s->first)
				break;
		}
		push_last(stack, get_stack_len(s) - 1 - temp);
		i = i->next;
		if (i == s->first)
			break;
	}
	return (stack);
}

void	sort(t_deq *a, t_deq *b)
{
	int		i;
	int		j;
	int		len;
	int		max_bits;
	int		num;

	i = 0;
	len = get_stack_len(a);
	while ((len - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if (a->last->data & 1 << i)
			{
				reverse_rotate(a);
				ft_putstr("rra\n");
				print_all(a, b);
			}
			else
			{
				push(a, b);
				ft_putstr("pa\n");
				print_all(a, b);
			}
			j++;
		}
		i++;
	}
	while (b->first)
	{
		ft_putstr("pb\n");
		push(b, a);
	}
	print_all(a, b);
}

//void	sort(t_deq *a, t_deq *b, int n)
//{
//	t_node *a_node;
//	t_node *b_node;
//	int		len;
//
//	len = get_stack_len(a);
//	a_node = a->first;
//	b_node = b->first;
//	while (a_node)
//	{
//		if (a_node->data & n)
//			push(a, b);
//		else
//			reverse_rotate(a);
//		a_node = a_node->next;
//		if (a_node == a->first)
//			break;
//	}
//	while (b_node)
//	{
//		push(b, a);
//	}
//	if (n == 4)
//		return ;
//	ft_putstr("a\n");
//	print_all(a);
//	ft_putstr("b\n");
//	print_all(b);
//	sort(a, b, n * 2);
//}
int main()
{
	t_deq *a;
	t_deq *b;
	t_deq *s_a;

	init_deq(&a);
	init_deq(&b);
	push_last(a, 1);
	push_last(a, 2);
	push_last(b, 3);

	s_a = simplify(a);
	print_all(a, b);
//	sort(s_a, b);
}
