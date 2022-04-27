/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:27 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 07:24:19 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* *************************** *\
|*	keycode 0 && 123 => left   *|
|*	keycode 1 && 125 => down   *|
|*	keycode 2 && 124 => right  *|
|*	keycode 13 && 126 => up    *|
\* *************************** */

int	key_hook(int keycode, t_mlx *s)
{
	if (keycode == 53)
		free_close(s);
	else if (keycode == 2 || keycode == 124)
		character_move(s, 1);
	else if (keycode == 0 || keycode == 123)
		character_move(s, 2);
	else if (keycode == 13 || keycode == 126)
		character_move(s, 3);
	else if (keycode == 1 || keycode == 125)
		character_move(s, 4);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	s;

	before_mlx_init(&s, argc, argv[1]);
	s.mlx = mlx_init();
	s.window = mlx_new_window(s.mlx, \
	((s.window_w - 1) * 60), (s.window_h * 60), "So_long");
	add_images(&s);
	put_map(&s);
	mlx_key_hook(s.window, key_hook, &s);
	mlx_hook(s.window, 17, 03, free_close, &s);
	mlx_loop(s.mlx);
}
