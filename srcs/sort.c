/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:27:43 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 13:08:22 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *s)
{
	int		prev_data;
	t_node	*node;

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

void	sort_three(t_list *a)
{
	if (0 == a->first->data)
	{
		if (2 == a->last->data)
			swap(a);
		reverse_rotate(a);
	}
	else if (0 == a->first->next->data)
	{
		if (2 == a->last->data)
			rotate(a);
		else
			swap(a);
	}
	else if (0 == a->last->data & 1 == a->first->data)
	{
		reverse_rotate(a);
		swap(a);
	}
}

void	sort_five(t_list *a, t_list *b)
{
	int		len;

	len = a->size;
	while (len-- && !is_sorted(a))
	{
		if (a->last->data > 2)
			push(a, b);
		else
			rotate(a);
	}
	sort_three(a);
	if (b->first->data > b->last->data)
		rotate(b);
	len = b->size;
	while (b->first)
		push(b, a);
	while (len--)
		rotate(a);
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
	while (++idx < max_bit)
	{
		if (is_sorted(a))
			return ;
		len = a->size;
		while (len--)
		{
			if (a->last->data >> idx & 1)
				rotate(a);
			else
				push(a, b);
		}
		while (b->size)
			push(b, a);
	}
}

t_list	*simplify(t_list *s)
{
	t_node	*i;
	t_node	*j;
	t_list	*stack;
	int		data;

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
