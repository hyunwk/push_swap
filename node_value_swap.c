/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_value_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/24 12:50:31 by hyunwkim         ###   ########.fr       */
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
	char	name;
	int		size;
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

void init_deq(t_deq **s, char c)
{
	*s = (t_deq *)malloc(sizeof(t_deq));
	if ((*s) == 0)
	{
		ft_putstr("malloc error.\n");
		exit(1);
	}
	(*s)->name = c;
	(*s)->size = 0;
	(*s)->first = 0;
	(*s)->last= 0;
}

void push_first(t_deq *s, int val)
{
	t_node *new;
	
	new = make_node(val);
	new->next = s->first;
	if (s->first != NULL)
		s->first->prev = new;
	s->first = new;
	if (s->first->next == NULL)
		s->last = s->first;
	s->size++;
}

void push_last(t_deq *s, int val)
{
	t_node *new;
	
	new = make_node(val);
	if (s->first == NULL)
		push_first(s, val);
	else
	{
		s->last->next = new;
		new->prev = s->last;
		s->last = new;
	}
	s->size++;
}

int		pop_first(t_deq *s)
{
	int		removed_data;

	if (s->first == NULL)
		error("no data to pop_first");
	removed_data = s->first->data;
	s->first->data = 0;

	if (s->first->next != NULL)
		s->first->next->prev = NULL;

	s->first = s->first->next;

	if (s->first == NULL)
		s->last = NULL;
	s->size--;
	return (removed_data);
}
int		pop_last(t_deq *s)
{
	int		removed_data;


	if (s->first == NULL)
		error("no data to pop_last");
	removed_data = s->last->data;

	s->last->data = 0;

	if (s->last->prev != NULL)
		s->last->prev->next = NULL;

	s->last = s->last->prev;

	if (s->last == NULL)
		s->first = NULL;
	s->size--;
	return (removed_data);
}

void swap(t_deq *s)
{
	t_node *temp;
	int		data;
	int		data_last;
	int		data_last_prev;

	//	1. 아무것도 없을 경우
	if (!(s->first))
		return ;
	// 2. data 하나 있을 경우
	if (s->first == s->first->next)
		return ;
	data = s->last->data;
	s->last->data = s->last->prev->data;
	s->last->prev->data = data;
	ft_putchar('s');
	ft_putchar(s->name);
	ft_putchar('\n');
}

int get_stack_len(t_deq *s)
{
	int len;
	t_node *node;

	len = 0;
	node = s->first;
	while (node != s->last)
	{
		node = node->next;
		len++;
	}
	if (node == s->last)
		len += 1;
	return (len);
}

void push(t_deq *a, t_deq *b)
{
	push_last(b, pop_last(a));
	ft_putchar('p');
	ft_putchar(b->name);
	ft_putchar('\n');
}

void rotate(t_deq *s)
{
	push_last(s, pop_first(s));
	ft_putchar('r');
	ft_putchar(s->name);
	ft_putchar('\n');
}

void reverse_rotate(t_deq *s)
{
	push_first(s, pop_last(s));
	ft_putstr("rr");
	ft_putchar(s->name);
	ft_putchar('\n');
}

#include<stdio.h>

void print_all(t_deq *s, t_deq *s2)
{
//	t_node *node;
//
//	node = s->last;
//	while (node)
//	{
//		printf("%d ", node->data);
//		node = node->prev;
//	}
//	return ;
//}	
	t_node *node;
	t_node *node_2;
	int		len;
	int		len_1;
	int		len_2;
	int		k;

	len_1 = s->size;
	len_2 = s2->size;
	if (s->size > s2->size)
	{
		k = s->size - s2->size + 1;
		len = s->size;
	}
	else
	{
		k = s2->size - s->size + 1;
		len = s2->size;
	}
	node = s->last;
	node_2 = s2->last;
	while (len--)
	{
		if (s->size > s2->size || !k)
		{
			printf("%d",node->data);
			node = node->prev;
		}
		printf("    ");
		if (s2->size > s->size || !k)
		{
			printf("%d",node_2->data);
			node_2 = node_2->prev;
		}
		k--;
		printf("\n");
	}
	printf("   a       b\n"); 
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
		temp = node->data;
	}
	return (0);
}
void sort_three(t_deq *a)
{
	if (0 == a->first->data)
	{
		if (2 == a->last->data)
			swap(a);
		rotate(a);
	}
	if (0 == a->first->next->data)
	{
		if (2 == a->last->data)
			reverse_rotate(a);
		else
			swap(a);
	}
	else 
	{
		reverse_rotate(a);
		swap(a);
	}
}
void sort_five(t_deq *a, t_deq *b)
{
	int		len;

	len = a->size;
	while (len--)
	{
		if (a->last->data > 2)
			push(a, b);
		else
			reverse_rotate(a);
	}
	sort_three(a);
	len = a->size + b->size;
	if (b->last->data > b->first->data)
		rotate(b);
	push(b, a);
	push(b, a);
	print_all(a, b);
	exit(0);
}

void	sort(t_deq *a, t_deq *b)
{
	int		i;
	int		j;
	int		len;
	int		max_bits;
	if (get_stack_len(a) <= 3)
	{	
		sort_three(a);
		exit(0);
	}
	if (get_stack_len(a) <= 5)
	{
		sort_five(a, b);
		exit(0);
	}
	i = 0;
	len = get_stack_len(a);
	while (len)
	{
		len /= 2;
		max_bits++;
	}
	while (i < max_bits)
	{
		j = 0;
		while (j < get_stack_len(a))
		{
			print_all(a, b);
			if (is_sorted(a))
				return ;
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
			ft_putstr("pb\n");
			push(b, a);
		}
	}
}

void error(char *s)
{
	ft_putstr(s);
	exit(1);
}
t_deq *check_argv(int argc, char **s)
{
	int num;
	char **splited;
	t_deq *a;
	t_node *node;

	init_deq(&a, 'a');
	while (*(++s))
	{
		splited = ft_split(*s, ' ');
		while (*splited)
		{	
			num = ft_atoi(*splited);
			if ((num < -2147483648) || (num > 2147483647))
				error("argument error");
			node = (a)->first;
			while (node)
			{
				if (node ->data == num)
					return (0);
				node = node->next;
			}
			push_first(a, num);
			splited++;
		}
	}
	if (is_sorted(a))
		error("\n");
	return (a);
}

t_deq *simplify(t_deq *s)
{
	t_node *i;
	t_node *j;
	t_deq *stack;
	int data;

	init_deq(&stack, 'a');
	i = s->last;
	while (i)
	{
		j = s->last;
		data = 0;
		while (j)
		{
			if (i->data > j->data)
				data += 1;
			j = j->prev;
		}
		push_first(stack, data);
		i = i->prev;
	}
	// need to free all node
	free(s);
	return (stack);
}

int main(int argc, char **argv)
{
	t_deq *a;
	t_deq *b;

	if (argc == 1)
		return (0);
	init_deq(&b, 'b');
	a = simplify(check_argv(argc, argv));
	if (!a)
		return (0);
	sort(a, b);
}
