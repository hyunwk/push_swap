/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:29:00 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 13:07:40 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_first(t_list *s, int val)
{
	t_node	*new;

	new = make_node(val);
	new->next = s->first;
	if (s->first != NULL)
		s->first->prev = new;
	s->first = new;
	if (s->first->next == NULL)
		s->last = s->first;
	s->size++;
}

void	push_last(t_list *s, int val)
{
	t_node	*new;

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

int	pop_first(t_list *s)
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

int	pop_last(t_list *s)
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

void	free_stack(t_list *s)
{
	t_node	*node;
	t_node	*temp;

	node = s->first;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(s);
}
