/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:57:46 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_basic(t_mlx *s)
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
}

static void	put_flag1(t_mlx *s)
{
	s->e[0].image = mlx_xpm_file_to_image(s->mlx, E_1, &s->p[0].w, &s->p[0].h);
	s->e[1].image = mlx_xpm_file_to_image(s->mlx, E_2, &s->p[0].w, &s->p[0].h);
	s->e[2].image = mlx_xpm_file_to_image(s->mlx, E_3, &s->p[0].w, &s->p[0].h);
	s->e[3].image = mlx_xpm_file_to_image(s->mlx, E_4, &s->p[0].w, &s->p[0].h);
	s->e[4].image = mlx_xpm_file_to_image(s->mlx, E_5, &s->p[0].w, &s->p[0].h);
	s->e[5].image = mlx_xpm_file_to_image(s->mlx, E_6, &s->p[0].w, &s->p[0].h);
	s->e[6].image = mlx_xpm_file_to_image(s->mlx, E_7, &s->p[0].w, &s->p[0].h);
	s->e[7].image = mlx_xpm_file_to_image(s->mlx, E_8, &s->p[0].w, &s->p[0].h);
	s->e[8].image = mlx_xpm_file_to_image(s->mlx, E_9, &s->p[0].w, &s->p[0].h);
	s->e[9].image = mlx_xpm_file_to_image(s->mlx, E_10, &s->p[0].w, &s->p[0].h);
	s->e[10].image = mlx_xpm_file_to_image(s->mlx, E_11, \
	&s->p[0].w, &s->p[0].h);
	s->e[11].image = mlx_xpm_file_to_image(s->mlx, E_12, \
	&s->p[0].w, &s->p[0].h);
	s->e[12].image = mlx_xpm_file_to_image(s->mlx, E_13, \
	&s->p[0].w, &s->p[0].h);
	s->e[13].image = mlx_xpm_file_to_image(s->mlx, E_14, \
	&s->p[0].w, &s->p[0].h);
	s->e[14].image = mlx_xpm_file_to_image(s->mlx, E_15, \
	&s->p[0].w, &s->p[0].h);
	s->e[15].image = mlx_xpm_file_to_image(s->mlx, E_16, \
	&s->p[0].w, &s->p[0].h);
	s->e[16].image = mlx_xpm_file_to_image(s->mlx, E_17, \
	&s->p[0].w, &s->p[0].h);
}

static void	put_flag2(t_mlx *s)
{
	s->e[17].image = mlx_xpm_file_to_image(s->mlx, E_18, \
	&s->p[0].w, &s->p[0].h);
	s->e[18].image = mlx_xpm_file_to_image(s->mlx, E_19, \
	&s->p[0].w, &s->p[0].h);
	s->e[19].image = mlx_xpm_file_to_image(s->mlx, E_20, \
	&s->p[0].w, &s->p[0].h);
	s->e[20].image = mlx_xpm_file_to_image(s->mlx, E_21, \
	&s->p[0].w, &s->p[0].h);
	s->e[21].image = mlx_xpm_file_to_image(s->mlx, E_22, \
	&s->p[0].w, &s->p[0].h);
	s->e[22].image = mlx_xpm_file_to_image(s->mlx, E_23, \
	&s->p[0].w, &s->p[0].h);
	s->e[23].image = mlx_xpm_file_to_image(s->mlx, E_24, \
	&s->p[0].w, &s->p[0].h);
	s->e[24].image = mlx_xpm_file_to_image(s->mlx, E_25, \
	&s->p[0].w, &s->p[0].h);
	s->e[25].image = mlx_xpm_file_to_image(s->mlx, E_26, \
	&s->p[0].w, &s->p[0].h);
}

static void	put_enemy(t_mlx *s)
{
	s->t[0].image = mlx_xpm_file_to_image(s->mlx, T_1, &s->t[0].w, &s->t[0].h);
	s->t[1].image = mlx_xpm_file_to_image(s->mlx, T_2, &s->t[0].w, &s->t[0].h);
	s->t[2].image = mlx_xpm_file_to_image(s->mlx, T_3, &s->t[0].w, &s->t[0].h);
	s->t[3].image = mlx_xpm_file_to_image(s->mlx, T_4, &s->t[0].w, &s->t[0].h);
	s->t[4].image = mlx_xpm_file_to_image(s->mlx, T_5, &s->t[0].w, &s->t[0].h);
	s->t[5].image = mlx_xpm_file_to_image(s->mlx, T_6, &s->t[0].w, &s->t[0].h);
	s->t[6].image = mlx_xpm_file_to_image(s->mlx, T_7, &s->t[0].w, &s->t[0].h);
	s->t[7].image = mlx_xpm_file_to_image(s->mlx, T_8, &s->t[0].w, &s->t[0].h);
	s->t[8].image = mlx_xpm_file_to_image(s->mlx, T_9, &s->t[0].w, &s->t[0].h);
	s->t[9].image = mlx_xpm_file_to_image(s->mlx, T_10, &s->t[0].w, &s->t[0].h);
	s->t[10].image = mlx_xpm_file_to_image(s->mlx, T_11, \
	&s->t[0].w, &s->t[0].h);
	s->t[11].image = mlx_xpm_file_to_image(s->mlx, T_12, \
	&s->t[0].w, &s->t[0].h);
	s->t[12].image = mlx_xpm_file_to_image(s->mlx, T_13, \
	&s->t[0].w, &s->t[0].h);
	s->t[13].image = mlx_xpm_file_to_image(s->mlx, T_14, \
	&s->t[0].w, &s->t[0].h);
	s->t[14].image = mlx_xpm_file_to_image(s->mlx, T_15, \
	&s->t[0].w, &s->t[0].h);
	s->t[15].image = mlx_xpm_file_to_image(s->mlx, T_16, \
	&s->t[0].w, &s->t[0].h);
}

void	add_images(t_mlx *s)
{
	put_basic(s);
	put_flag1(s);
	put_flag2(s);
	put_enemy(s);
}
