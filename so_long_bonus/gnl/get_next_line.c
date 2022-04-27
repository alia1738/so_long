/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:07 by aalsuwai          #+#    #+#             */
/*   Updated: 2021/12/11 18:31:18 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ii;
	char	*s;

	if (s1 == 0)
		ii = s_len(s2);
	else if (s2 == 0)
		ii = s_len(s1);
	else
		ii = s_len(s1) + s_len(s2);
	s = malloc((ii + 1) * sizeof(char));
	if (s == 0)
		return (0);
	ii = 0;
	i = 0;
	while (s1 && s1[i])
		s[ii++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		s[ii++] = s2[i++];
	s[ii] = 0;
	ft_free(s1, s2, 0);
	return (s);
}

static char	*ft_substr(char *s, int start, int len)
{
	int		ii;
	char	*ss;

	if (len > s_len(s))
		len = s_len(s) - start;
	else if (start > s_len(s))
		len = 0;
	ss = (char *)malloc((len + 1) * sizeof(char));
	if (ss == 0)
		return (0);
	if (start > s_len(s))
	{
		ss[0] = 0;
		return (ss);
	}
	ii = 0;
	while (s[start] && ii < len)
	{
		ss[ii] = s[start];
		ii++;
		start++;
	}
	ss[ii] = 0;
	return (ss);
}

static t_return_remain	separate(char *org, t_return_remain new)
{
	int	i;
	int	rem_len;
	int	ret_len;

	i = 0;
	while (org[i] && org[i] != '\n')
		i++;
	i++;
	ret_len = i;
	rem_len = s_len(org) - ret_len;
	new.ret = ft_substr(org, 0, ret_len);
	if (rem_len == 0)
		new.rem = 0;
	else
		new.rem = ft_substr(org, (ret_len), (rem_len));
	ft_free(org, 0, 0);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_return_remain	s;
	static ssize_t			check = 1;
	char					*str;

	s.ret = 0;
	while (check && s.ret == 0)
	{
		str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (s.rem == 0 || new_line_check(s.rem) == 0)
		{
			check = read(fd, str, BUFFER_SIZE);
			if (check == -1)
				ft_free(s.ret, s.rem, str);
			if (check == -1)
				return (0);
		}
		if (check == 0)
			ft_free(str, s.ret, 0);
		if (check == 0)
			return (s.rem);
		s.rem = ft_strjoin(s.rem, str);
		if (new_line_check(s.rem))
			s = separate(s.rem, s);
	}
	return (s.ret);
}
