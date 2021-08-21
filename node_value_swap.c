/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_value_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/21 15:56:56 by hyunwkim         ###   ########.fr       */
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

	origin_last = s->last;
	removed_data = origin_last->data;
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
		s->last->prev->next = origin_last->next;
		s->first->prev = origin_last->prev;
		s->last = origin_last->prev;
	}
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
	data = s->last->data;
	s->last->data = s->last->prev->data;
	s->last->prev->data = data;
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
	printf("        a               b\n"); 
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
		push_last(stack, get_stack_len(s)  - temp);
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

	i = 0;
	len = get_stack_len(a);
	while (len)
	{
		len /= 2;
		max_bits++;
	}
	len = get_stack_len(a);
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			print_all(a, b);
			if (a->last->data >> i & 1)
			{
				reverse_rotate(a);
				ft_putstr("rra\n");
			}
			else
			{
				push(a, b);
				ft_putstr("pa\n");
			}
			j++;
		}
		i++;
		while (b->first)
		{
			print_all(a, b);
			ft_putstr("pb\n");
			push(b, a);
		}
	}
	print_all(a, b);
}

int is_sorted(t_deq *s)
{
	int		temp;
	t_node *node;

	node = s->first;
	temp = node->data;
	while (node)
	{
		node = node->next;
		if (node == s->first)
			return (1);
		if (temp - node->data != 1)
			return (0);
	}
	return (1);
}

t_deq *check_argv(int argc, char **s)
{
	int num;
	char **splited;
	t_deq *a;
	t_node *node;

	init_deq(&a);
	while (*(++s))
	{
		splited = ft_split(*s, ' ');
		while (*splited)
		{	
			num = ft_atoi(*splited);
			if (num == -1)
				return (0);
			node = (a)->first;
			while (node)
			{
				if (node ->data == num)
					return (0);
				node = node->next;
				if (node == a->first)
					break;
			}
			push_last(a, num);
			splited++;
		}
	}
	if (is_sorted(a))
		return (0);
	return (a);
}

int main(int argc, char **argv)
{
	t_deq *a;
	t_deq *b;

	if (argc == 1)
		return (0);
	init_deq(&b);
	a = check_argv(argc, argv);
	if (!a)
		return (0);
	sort(simplify(a), b);
}
