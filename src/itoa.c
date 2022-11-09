/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:24 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:57:49 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count(int n)
{
	int	count;
	int	c;

	count = 0;
	c = n;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	if (n == 0)
		count += 1;
	if (n < 0)
		return (count + 2);
	return (count + 1);
}

static char	*copy_part(int n, int save, char *s, int c)
{
	while (c > 0)
	{
		s[c] = (n % 10) + 48;
		n = n / 10;
		c--;
	}
	if (n > 0)
		s[0] = n + 48;
	if (save < 0)
		s[0] = '-';
	if (save == 0)
		s[0] = '0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		c;
	int		save;

	save = n;
	c = count(n);
	if (n < 0 && n != INT_MIN)
		n = n * -1;
	s = (char *)malloc(c * sizeof(char));
	if (s == 0)
		return (NULL);
	c--;
	s[c] = 0;
	c--;
	if (save == INT_MIN)
	{
		s[c] = '8';
		n = 214748364;
		c--;
	}
	s = copy_part(n, save, s, (c));
	return (s);
}
