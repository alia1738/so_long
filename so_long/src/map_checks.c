/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:31 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 07:14:14 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_have(t_mlx *s, char c)
{
	int	h;
	int	w;
	int	count;

	h = 0;
	count = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w] && s->map[h][w] != '\n')
		{
			if (s->map[h][w] == c)
				count++;
			w++;
		}
		h++;
	}
	return (count);
}

int	check_map_edges(t_mlx *s, char c)
{
	int	h;
	int	w;
	int	count;

	h = 0;
	count = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w] && s->map[h][w] != '\n')
		{
			if (!h && s->map[h][w] != c)
				count++;
			else if (!w && s->map[h][w] != c)
				count++;
			else if (h == s->window_h - 1 && s->map[h][w] != c)
				count++;
			else if (w == s->window_w - 2 && s->map[h][w] != c)
				count++;
			w++;
		}
		h++;
	}
	return (count);
}

int	check_map_var(t_mlx *s)
{
	int	h;
	int	w;
	int	count;

	h = 0;
	count = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w] && s->map[h][w] != '\n')
		{
			if (s->map[h][w] != '1' && s->map[h][w] != '0' && \
			s->map[h][w] != 'P' && s->map[h][w] != 'E' && \
			s->map[h][w] != 'C')
				count++;
			w++;
		}
		h++;
	}
	return (count);
}

int	check_map_layout(t_mlx *s)
{
	int	h;
	int	w;

	h = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w] && s->map[h][w] != '\n')
			w++;
		if (w != s->window_w - 1)
			return (1);
		h++;
	}
	return (0);
}
