/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_value_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/24 15:05:46 by hyunwkim         ###   ########.fr       */
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

typedef struct s_list
{
	char	name;
	int		size;
	t_node	*first;
	t_node	*last;
}					t_list;

t_node *make_node(int val)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error();
	node->data = val;
	node->prev = 0;
	node->next = 0;
	return (node);
}

void init_list(t_list **s, char c)
{
	*s = (t_list *)malloc(sizeof(t_list));
	if ((*s) == 0)
		error();
	(*s)->name = c;
	(*s)->size = 0;
	(*s)->first = 0;
	(*s)->last= 0;
}

void push_first(t_list *s, int val)
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

void push_last(t_list *s, int val)
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
		s->size++;
	}
}

int		pop_first(t_list *s)
{
	int		removed_data;
	t_node	*origin_first;

	if (s->first == NULL)
		error();
	origin_first = s->first;
	removed_data = origin_first->data;
	origin_first->data = 0;

	if (origin_first->next != NULL)
		origin_first->next->prev = NULL;

	s->first = origin_first->next;
	free(origin_first);
	if (s->first == NULL)
		s->last = NULL;
	s->size--;
	return (removed_data);
}
int		pop_last(t_list *s)
{
	int		removed_data;
	t_node	*origin_last;

	if (s->first == NULL)
		error();
	origin_last = s->last;
	removed_data = origin_last->data;

	origin_last->data = 0;

	if (origin_last->prev != NULL)
		origin_last->prev->next = NULL;

	s->last = origin_last->prev;
	free(origin_last);
	if (s->last == NULL)
		s->first = NULL;
	s->size--;
	return (removed_data);
}

void swap(t_list *s)
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

int get_stack_len(t_list *s)
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

void push(t_list *a, t_list *b)
{
	push_last(b, pop_last(a));
	ft_putchar('p');
	ft_putchar(b->name);
	ft_putchar('\n');
}

void rotate(t_list *s)
{
	push_last(s, pop_first(s));
	ft_putchar('r');
	ft_putchar(s->name);
	ft_putchar('\n');
}

void reverse_rotate(t_list *s)
{
	push_first(s, pop_last(s));
	ft_putstr("rr");
	ft_putchar(s->name);
	ft_putchar('\n');
}

#include<stdio.h>

void print_all(t_list *s, t_list *s2)
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
	int		k;

	if (s->size > s2->size)
	{
		k = s->size - s2->size;
		len = s->size;
	}
	else if (s->size < s2->size)
	{
		k = s2->size - s->size;
		len = s2->size;
	}
	else
	{
		k = s->size;
		len = s->size;
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
		if (k)
			k--;
		printf("\n");
	}
	printf("-------\na    b\n"); 
	}

int is_sorted(t_list *s)
{
	int		prev_data;
	t_node *node;

	node = s->last;
	prev_data = -1;
	while (node)
	{
		if (prev_data < node->data)
		{
			prev_data = node->data;
			node = node->prev;
		}
		else
			return (0);
	}
	return (1);
}
void sort_three(t_list *a)
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
void sort_five(t_list *a, t_list *b)
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

void	sort(t_list *a, t_list *b)
{
	int		idx;
	int		len;
	int		max_bit;

	idx = -1;
	max_bit = 0;
	while ((a->size - 1) >> max_bit)
		max_bit++;
	while (idx++ < max_bit)
	{
		len = a->size;
		if (is_sorted(a))
			return ;
		while (len--)
		{
			if (a->last->data >> idx & 1)
				reverse_rotate(a);
			else
				push(a, b);
		}
		while (b->size)
			push(b, a);
	}
	print_all(a, b);
}

void error(void)
{
	ft_putstr("Error\n");
	exit(1);
}
void free_stack(t_list *s)
{
	t_node *node;
	t_node *temp;

	node = s->first;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(s);
}
t_list *check_argv(int argc, char **s)
{
	int num;
	int idx;
	char **splited;
	t_list *a;
	t_node *node;

	init_list(&a, 'a');
	while (*(++s))
	{
		splited = ft_split(*s, ' ');
		idx = 0;
		while (splited[idx])
		{	
			// atoi error check
			num = ft_atoi(splited[idx]);
			free(splited[idx]);
			if ((num < -2147483648) || (num > 2147483647))
				error();
			node = (a)->first;
			while (node)
			{
				if (node ->data == num)
					return (0);
				node = node->next;
			}
			push_first(a, num);
			idx++;
		}
		free(splited);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		exit(1);
	}
	return (a);
}



t_list *simplify(t_list *s)
{
	t_node *i;
	t_node *j;
	t_list *stack;
	int data;

	init_list(&stack, 'a');
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
	free_stack(s);
	return (stack);
}
#include <string.h>
int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	if (argc == 1)
		return (0);
	init_list(&b, 'b');
	a = simplify(check_argv(argc, argv));
	if (!a)
		return (0);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
	else 
		sort(a, b);
	free_stack(a);
	free_stack(b);
	while (1)
		;
	return (0);
}
