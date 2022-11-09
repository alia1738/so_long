/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_helpers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:43 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/05/30 17:56:15 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turtles_count(t_mlx *s)
{
	int	h;
	int	w;

	h = 0;
	while (s->map[h])
	{
		w = 0;
		while (s->map[h][w] && s->map[h][w] != '\n')
		{
			if (s->map[h][w] == 'T')
				s->t_count++;
			w++;
		}
		h++;
	}
}

void	do_turtle_stuff(t_mlx *s)
{
	int	i;

	i = 0;
	s->t_h = malloc(s->t_count * sizeof(int));
	if (!s->t_h)
	{
		printf("%sError: fatal error%s\n", RED, RESET);
		exit(1);
	}
	s->t_w = malloc(s->t_count * sizeof(int));
	if (!s->t_w)
	{
		printf("%sError: fatal error%s\n", RED, RESET);
		exit(1);
	}
	while (i < s->t_count)
	{
		s->t_h[i] = 0;
		s->t_w[i] = 0;
		i++;
	}
}

void	before_mlx_init(t_mlx *s, int argc, char *arg)
{
	if (argc != 2)
	{
		printf("%sError: wrong number of arguments%s\n", RED, RESET);
		printf("%s... <executable>  <file> ...%s\n", YELLOW, RESET);
		exit(1);
	}
	initialize(s);
	get_window_w(s, arg);
	get_window_h(s, arg);
	if (check_map_var(s) || check_map_edges(s, '1') || \
	check_map_layout(s) || check_map_have(s, 'P') != 1 || \
	check_map_have(s, 'C') < 1 || check_map_have(s, 'E') != 1)
	{
		printf("%sError: check the map%s\n", RED, RESET);
		free_array(s->map);
		if (!s->t_count)
		{
			free(s->t_h);
			free(s->t_w);
		}
		exit(1);
	}
	turtles_count(s);
	if (s->t_count)
		do_turtle_stuff(s);
}

void	do_before_move(t_mlx *s)
{
	mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
	(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (s->map[s->p_h][s->p_w] == 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->e[7].image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
}

void	do_after_move(t_mlx *s)
{
	int	i;

	i = 0;
	while (i < (s->window_w - 1) * 60)
	{
		mlx_put_image_to_window(s->mlx, s->window, s->g.image, i, 0);
		i += 60;
	}
	mlx_string_put(s->mlx, s->window, 5, 30, 0xF4D03F, "Moves:");
	mlx_string_put(s->mlx, s->window, 5, (30 + 18), 0xF4D03F, "Mellon:");
	mlx_string_put(s->mlx, s->window, (60 + 5), 30, 0xe8dcdc, \
	ft_itoa(s->urlda[4]));
	mlx_string_put(s->mlx, s->window, (60 + 5), (30 + 18), 0xe8dcdc, \
	ft_itoa(s->c_count));
	if (s->map[s->p_h][s->p_w] == 'T')
	{
		printf("\n%s**** LOSER! ****%s\n", RED, RESET);
		free_close(s);
	}
	if (!s->c_count && s->map[s->p_h][s->p_w] == 'E')
	{
		printf("\n%s**** WoOoOw YoU wOn! ****%s\n", GREEN, RESET);
		free_close(s);
	}
}
