/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:12 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/05/30 17:53:50 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *s, char *ss, char *sss)
{
	free(s);
	free(ss);
	free(sss);
}

int	s_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	new_line_check(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	*ft_calloc(ssize_t count, ssize_t size)
{
	ssize_t	i;
	void	*s;

	i = 0;
	s = (void *)malloc(count * size);
	if (!s)
		return (NULL);
	while (i < count * size)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}
