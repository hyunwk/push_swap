/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:13:27 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/17 11:15:46 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	*check_argv(int argc, char **s)
{
	int *stack;
	int idx;
	int check_idx;
	int len;

	// int 배열 생성
	stack = (int *)malloc(sizeof(int) * argc + 1);
	if (!stack)
		return (0);
	idx = 0;
	while (s[idx + 1])
	{
		stack[idx] = ft_atoi(s[idx + 1]);
		printf("stack[%d] = %d\n", idx, stack[idx]);
		// int 범위, not int 
		if (stack[idx] == -1)
		{
			free(stack);
			return (0);
		}
		// 중복검사 
		check_idx = 1;
		while (check_idx < idx)
		{
			if (stack[check_idx] == stack[idx])
			{
				free(stack);
				return (0);
			}
			check_idx++;
		}
		idx++;
	}
	stack[idx] = 0;
	return (stack);
}
int main(int argc, char **argv)
{
	int *stack;

	stack = check_argv(argc, argv);
	if (!stack)
	{
		ft_putstr("\nError");
		exit(1);
	}

}
