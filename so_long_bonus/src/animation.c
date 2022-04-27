/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:09 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:57:40 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flag_move(t_mlx *s)
{
	static int	i;

	if (s->c_count == 0)
	{
		mlx_put_image_to_window(s->mlx, s->window, \
		s->b.image, (s->e_w * s->b.w), (s->e_h * s->b.h));
		mlx_put_image_to_window(s->mlx, s->window, \
		s->e[i].image, (s->e_w * s->b.w), (s->e_h * s->b.h));
		i++;
		if (i == 25)
			i = 20;
	}
}

static void	enemy_move(t_mlx *s, int ii)
{
	static int	i;

	if (s->t_count)
	{
		turtle_walk(s);
		mlx_put_image_to_window(s->mlx, s->window, \
		s->b.image, (s->t_w[ii] * s->g.w), (s->t_h[ii] * s->g.h));
		mlx_put_image_to_window(s->mlx, s->window, \
		s->t[i++].image, (s->t_w[ii] * s->g.w), ((s->t_h[ii] * s->g.h) + 22));
		if (i == 15)
		{
			s->t_move++;
			i = 0;
		}
	}
}

int	animation(t_mlx *s)
{
	static int	ii;
	int			time;

	time = 35000;
	usleep(time);
	enemy_move(s, ii++);
	if (ii == s->t_count)
		ii = 0;
	flag_move(s);
	usleep(time);
	return (0);
}
