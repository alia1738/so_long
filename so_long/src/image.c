/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 07:50:05 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_mlx *s)
{
	s->g.image = mlx_xpm_file_to_image(s->mlx, GROUND, &s->g.w, &s->g.h);
	s->c.image = mlx_xpm_file_to_image(s->mlx, MELLO, &s->c.w, &s->c.h);
	s->b.image = mlx_xpm_file_to_image(s->mlx, BACK, &s->b.w, &s->b.h);
	s->p[0].image = mlx_xpm_file_to_image(s->mlx, P_1, &s->p[0].w, &s->p[0].h);
	s->p[1].image = mlx_xpm_file_to_image(s->mlx, P_2, &s->p[1].w, &s->p[1].h);
	s->p[2].image = mlx_xpm_file_to_image(s->mlx, P_3, &s->p[2].w, &s->p[2].h);
	s->p[3].image = mlx_xpm_file_to_image(s->mlx, P_4, &s->p[3].w, &s->p[3].h);
	s->p[4].image = mlx_xpm_file_to_image(s->mlx, P_5, &s->p[4].w, &s->p[4].h);
	s->p[5].image = mlx_xpm_file_to_image(s->mlx, P_6, &s->p[5].w, &s->p[5].h);
	s->p[6].image = mlx_xpm_file_to_image(s->mlx, P_7, &s->p[6].w, &s->p[6].h);
	s->p[7].image = mlx_xpm_file_to_image(s->mlx, P_8, &s->p[7].w, &s->p[7].h);
	s->p[8].image = mlx_xpm_file_to_image(s->mlx, P_9, &s->p[8].w, &s->p[8].h);
	s->p[9].image = mlx_xpm_file_to_image(s->mlx, P_10, &s->p[9].w, &s->p[9].h);
	s->p[10].image = mlx_xpm_file_to_image(s->mlx, P_11, \
	&s->p[10].w, &s->p[10].h);
	s->p[11].image = mlx_xpm_file_to_image(s->mlx, P_12, \
	&s->p[11].w, &s->p[11].h);
	s->e[0].image = mlx_xpm_file_to_image(s->mlx, E_8, &s->e[0].w, &s->e[0].h);
	s->e[1].image = mlx_xpm_file_to_image(s->mlx, E_26, \
	&s->e[1].w, &s->e[1].h);
}
