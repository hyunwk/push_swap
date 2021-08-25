/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwkim <hyunwkim@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:16:37 by hyunwkim          #+#    #+#             */
/*   Updated: 2021/08/25 13:08:05 by hyunwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**freeall(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

int	get_len(char const *s, char set, int *i)
{
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (s[j] && s[j] == set)
		j++;
	while (s[j] && s[j] != set)
	{
		len++;
		j++;
	}
	*i += j;
	return (len);
}

char	*alloc_str(char	const *s, char c, int *idx)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = get_len(s + *idx, c, idx);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = s[i + *idx - len];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word_cnt;
	int		word_len;
	int		idx;

	if (!s)
		return (0);
	word_cnt = 0;
	word_len = 0;
	idx = 0;
	while (get_len(s + idx, c, &idx))
		word_cnt++;
	ptr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!ptr)
		return (0);
	idx = 0;
	while (idx < word_cnt)
	{
		ptr[idx++] = alloc_str(s, c, &word_len);
		if (!ptr[idx - 1])
			return (freeall(ptr));
	}
	ptr[idx] = 0;
	return (ptr);
}
