/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:34 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:58:00 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	show_img(t_mlx *s, int h, int w, int flag)
{
	if (flag == 1)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->b.image, (w * s->b.w), (h * s->b.h));
	else if (flag == 2)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->g.image, (w * s->g.w), (h * s->g.h));
	else if (flag == 3)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->p[1].image, (w * s->p[1].w), (h * s->p[1].h));
	else if (flag == 4)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->e[7].image, (w * s->g.w), (h * s->g.h));
	else if (flag == 5)
		mlx_put_image_to_window(s->mlx, s->window, \
		s->c.image, (w * s->c.w), (h * s->c.h));
}

static void	do_if(t_mlx *s, int h, int w, int flag)
{
	static int	i;

	if (flag == 1)
	{
		s->t_h[i] = h;
		s->t_w[i++] = w;
	}
	if (flag == 2)
	{
		s->p_h = h;
		s->p_w = w;
		show_img(s, h, w, 3);
	}
	if (flag == 3)
	{
		s->e_h = h;
		s->e_w = w;
		show_img(s, h, w, 4);
	}
	if (flag == 4)
	{
		show_img(s, h, w, 5);
		s->c_count++;
	}
}

static void	put_str(t_mlx *s)
{
	mlx_string_put(s->mlx, s->window, 5, 30, 0xF4D03F, "Moves:");
	mlx_string_put(s->mlx, s->window, 5, (30 + 18), 0xF4D03F, "Mellon:");
	mlx_string_put(s->mlx, s->window, (60 + 5), 30, 0xe8dcdc, \
	ft_itoa(s->urlda[4]));
	mlx_string_put(s->mlx, s->window, (60 + 5), (30 + 18), 0xe8dcdc, \
	ft_itoa(s->c_count));
}

void	put_map(t_mlx *s)
{
	int		h_count;
	int		w_count;

	h_count = 0;
	while (s->map[h_count])
	{
		w_count = 0;
		while (s->map[h_count][w_count])
		{
			show_img(s, h_count, w_count, 1);
			if (s->map[h_count][w_count] == 'T')
				do_if(s, h_count, w_count, 1);
			else if (s->map[h_count][w_count] == '1')
				show_img(s, h_count, w_count, 2);
			else if (s->map[h_count][w_count] == 'P')
				do_if(s, h_count, w_count, 2);
			else if (s->map[h_count][w_count] == 'E')
				do_if(s, h_count, w_count, 3);
			else if (s->map[h_count][w_count] == 'C')
				do_if(s, h_count, w_count, 4);
			w_count++;
		}
		h_count++;
	}
	put_str(s);
}
