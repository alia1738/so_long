/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:16 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 07:56:51 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_if_right(t_mlx *s)
{
	int	save;

	save = s->p_w * s->b.w;
	do_before_move(s);
	s->p_w += 1;
	if (s->map[s->p_h][s->p_w] == 'C')
	{
		s->map[s->p_h][s->p_w] = 0;
		s->c_count--;
	}
	if (s->map[s->p_h][s->p_w] != 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (!(s->urlda[1] % 2))
		mlx_put_image_to_window(s->mlx, s->window, s->p[7].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	else
		mlx_put_image_to_window(s->mlx, s->window, s->p[8].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	s->urlda[1]++;
	printf("%s%d%s\n", GREEN, ++s->urlda[4], RESET);
	do_after_move(s);
}

static void	do_if_left(t_mlx *s)
{
	do_before_move(s);
	s->p_w -= 1;
	if (s->map[s->p_h][s->p_w] == 'C')
	{
		s->map[s->p_h][s->p_w] = 0;
		s->c_count--;
		// if (!s->c_count)
		// 	mlx_put_image_to_window(s->mlx, s->window, s->e[1].image, \
		// 	(s->p_w * s->b.w), (s->p_h * s->b.h));
	}
	if (s->map[s->p_h][s->p_w] != 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (!(s->urlda[2] % 2))
		mlx_put_image_to_window(s->mlx, s->window, s->p[3].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	else
		mlx_put_image_to_window(s->mlx, s->window, s->p[5].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	s->urlda[2]++;
	printf("%s%d%s\n", BLUE, ++s->urlda[4], RESET);
	do_after_move(s);
}

static void	do_if_up(t_mlx *s)
{
	do_before_move(s);
	s->p_h -= 1;
	if (s->map[s->p_h][s->p_w] == 'C')
	{
		s->map[s->p_h][s->p_w] = 0;
		s->c_count--;
		// if (!s->c_count)
		// 	mlx_put_image_to_window(s->mlx, s->window, s->e[1].image, \
		// 	(s->p_w * s->b.w), (s->p_h * s->b.h));
	}
	if (s->map[s->p_h][s->p_w] != 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (!(s->urlda[0] % 2))
		mlx_put_image_to_window(s->mlx, s->window, s->p[9].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	else
		mlx_put_image_to_window(s->mlx, s->window, s->p[11].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	s->urlda[0]++;
	printf("%s%d%s\n", MAGENTA, ++s->urlda[4], RESET);
	do_after_move(s);
}

static void	do_if_down(t_mlx *s)
{
	do_before_move(s);
	s->p_h += 1;
	if (s->map[s->p_h][s->p_w] == 'C')
	{
		s->map[s->p_h][s->p_w] = 0;
		s->c_count--;
		// if (!s->c_count)
		// 	mlx_put_image_to_window(s->mlx, s->window, s->e[1].image, \
		// 	(s->p_w * s->b.w), (s->p_h * s->b.h));
	}
	if (s->map[s->p_h][s->p_w] != 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (!(s->urlda[3] % 2))
		mlx_put_image_to_window(s->mlx, s->window, s->p[0].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	else
		mlx_put_image_to_window(s->mlx, s->window, s->p[2].image, \
		(s->p_w * s->p[1].w), (s->p_h * s->p[1].h));
	s->urlda[3]++;
	printf("%s%d%s\n", LIGHT_BLUE, ++s->urlda[4], RESET);
	do_after_move(s);
}

void	character_move(t_mlx *s, int flag)
{
	if (flag == 1 && s->map[s->p_h][s->p_w + 1] != '1')
		do_if_right(s);
	else if (flag == 2 && s->map[s->p_h][s->p_w - 1] != '1')
		do_if_left(s);
	else if (flag == 3 && s->map[s->p_h - 1][s->p_w] != '1' )
		do_if_up(s);
	else if (flag == 4 && s->map[s->p_h + 1][s->p_w] != '1')
		do_if_down(s);
}
