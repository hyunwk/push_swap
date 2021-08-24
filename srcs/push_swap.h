/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:17:38 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/24 13:55:47 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

void	error(void);
int		ft_strlen(char *s);
void    ft_putstr(char *s);
void	ft_putchar(char c);
char	**ft_split(char const *s, char c);
long long ft_atoi(char *str);
int	ft_strcmp(const char *s1, const char *s2);
#endif
