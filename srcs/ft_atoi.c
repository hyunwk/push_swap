/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:15:47 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 00:36:49 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long ft_atoi(char *str)
{
	int				sign;
	long long		num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if ((num > 2147483647 && sign == 1)|| (num >2147483648 && sign == -1))
			return (num * sign);
	}
	if (num == 0 && sign == -1)
		error();
	if (!(*str))
		return (num * sign);
	return (2147483648);
}
