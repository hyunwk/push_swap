/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:26:44 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/28 16:10:43 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*make_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error();
	node->data = val;
	node->prev = 0;
	node->next = 0;
	return (node);
}

t_list	**init_list(t_list **s, char c)
{
	*s = (t_list *)malloc(sizeof(t_list));
	if ((*s) == 0)
		error();
	(*s)->name = c;
	(*s)->size = 0;
	(*s)->first = 0;
	(*s)->last = 0;
	return (s);
}

void	is_valid_num(long long num, t_node *node)
{
	if ((num < -2147483648) || (num > 2147483647))
		error();
	while (node)
	{
		if (node ->data == num)
			error();
		node = node->next;
	}
}

t_list	*check_argv(t_list **a, char **s)
{
	long long	num;
	int			idx;
	char		**splited;

	while (*(++s))
	{
		splited = ft_split(*s, ' ');
		if (!(*splited))
			error();
		idx = -1;
		while (splited[++idx])
		{
			num = ft_atoi(splited[idx]);
			is_valid_num(num, (*a)->first);
			push_first(*a, num);
			free(splited[idx]);
		}
		free(splited);
	}
	if (is_sorted(*a))
	{
		free_stack(*a);
		exit(1);
	}
	return (*a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	a = simplify(check_argv(init_list(&a, 'a'), argv));
	init_list(&b, 'b');
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 4 || a->size == 5)
		sort_five(a, b);
	else
		sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
