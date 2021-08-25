/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:28:06 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 13:31:25 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list *s)
{
	int		data;

	if (!(s->first))
		return ;
	if (s->first == s->first->next)
		return ;
	data = s->last->data;
	s->last->data = s->last->prev->data;
	s->last->prev->data = data;
	ft_putchar('s');
	ft_putchar(s->name);
	ft_putchar('\n');
}

void	push(t_list *a, t_list *b)
{
	push_last(b, pop_last(a));
	ft_putchar('p');
	ft_putchar(b->name);
	ft_putchar('\n');
}

void	rotate(t_list *s)
{
	push_first(s, pop_last(s));
	ft_putchar('r');
	ft_putchar(s->name);
	ft_putchar('\n');
}

void	reverse_rotate(t_list *s)
{
	push_last(s, pop_first(s));
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar(s->name);
	ft_putchar('\n');
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
