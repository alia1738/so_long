/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:46:20 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:57:29 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_images(t_mlx *s, int i, int flag)
{
	if (flag == 1)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->b.image, (s->t_w[i] * s->g.w), (s->t_h[i] * s->g.h));
	if (flag == 2)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->t[i].image, (s->t_w[i] * s->g.w), ((s->t_h[i] * s->g.h) + 22));
}

static void	do_if(t_mlx *s, int i, int flag)
{
	put_images(s, i, 1);
	s->map[s->t_h[i]][s->t_w[i]] = '0';
	if (flag == 1)
		s->t_w[i] += 1;
	else if (flag == 2)
		s->t_w[i] -= 1;
	else if (flag == 3)
		s->t_h[i] += 1;
	else if (flag == 4)
		s->t_h[i] -= 1;
	put_images(s, i, 2);
	s->map[s->t_h[i]][s->t_w[i]] = 'T';
}

void	turtle_walk(t_mlx *s)
{
	int	i;

	i = 0;
	if (s->t_move)
	{
		while (i < s->t_count)
		{
			if (s->map[s->t_h[i]][s->t_w[i] + 1] == '0')
				do_if(s, i, 1);
			else if (s->map[s->t_h[i]][s->t_w[i] - 1] == '0')
				do_if(s, i, 2);
			else if (s->map[s->t_h[i] + 1][s->t_w[i]] == '0')
				do_if(s, i, 3);
			else if (s->map[s->t_h[i] - 1][s->t_w[i]] == '0')
				do_if(s, i, 4);
			if (s->t_h[i] == s->p_h && s->t_w[i] == s->p_w)
			{
				printf("\n%s**** LOSER! ****%s\n", RED, RESET);
				free_close(s);
			}
			i++;
		}
		s->t_move = 0;
	}
}
