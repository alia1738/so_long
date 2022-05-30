/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_helpers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:43 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/05/30 17:40:30 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit(1);
	}
}

void	do_before_move(t_mlx *s)
{
	mlx_put_image_to_window(s->mlx, s->window, s->b.image, \
	(s->p_w * s->b.w), (s->p_h * s->b.h));
	if (s->map[s->p_h][s->p_w] == 'E' && s->c_count)
		mlx_put_image_to_window(s->mlx, s->window, s->e[0].image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
	else if (s->map[s->p_h][s->p_w] == 'E' && !s->c_count)
		mlx_put_image_to_window(s->mlx, s->window, s->e[1].image, \
		(s->p_w * s->b.w), (s->p_h * s->b.h));
}

void	do_after_move(t_mlx *s)
{
	if (!s->c_count)
		mlx_put_image_to_window(s->mlx, s->window, s->e[1].image, \
		(s->e_w * s->b.w), (s->e_h * s->b.h));
	if (!s->c_count && s->map[s->p_h][s->p_w] == 'E')
	{
		printf("\n%s**** WoOoOw YoU wOn! ****%s\n", GREEN, RESET);
		free_close(s);
	}
}
