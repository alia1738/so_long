/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:06:00 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 11:57:21 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include "limits.h"
# include "../gnl/get_next_line.h"

/*--------------------------structs--------------------------*/

typedef struct s_image
{
	void	*image;
	int		w;
	int		h;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;

	int		window_w;
	int		window_h;
	int		p_w;
	int		p_h;
	int		e_w;
	int		e_h;
	int		c_count;
	int		t_count;
	int		t_move;

	int		urlda[5];
	int		*t_w;
	int		*t_h;

	char	**map;

	t_image	g;
	t_image	c;
	t_image	b;
	t_image	p[12];
	t_image	e[26];
	t_image	t[16];
}	t_mlx;

/*------------------------- colors -------------------------*/

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define LIGHT_BLUE	"\x1B[36m"
# define RESET		"\x1B[0m"

/*---------------------- basic images ----------------------*/

# define BACK	"./used_graphics/back.xpm"
# define GROUND	"used_graphics/ground.xpm"
# define MELLO	"./used_graphics/mello.xpm"

/*------------------------ P images ------------------------*/

# define P_1	"used_graphics/p/d1.xpm"
# define P_2	"used_graphics/p/d2.xpm"
# define P_3	"used_graphics/p/d3.xpm"
# define P_4	"used_graphics/p/l1.xpm"
# define P_5	"used_graphics/p/l2.xpm"
# define P_6	"used_graphics/p/l3.xpm"
# define P_7	"used_graphics/p/r1.xpm"
# define P_8	"used_graphics/p/r2.xpm"
# define P_9	"used_graphics/p/r3.xpm"
# define P_10	"used_graphics/p/u1.xpm"
# define P_11	"used_graphics/p/u2.xpm"
# define P_12	"used_graphics/p/u3.xpm"

/*------------------------ E images ------------------------*/

# define E_1	"used_graphics/flag/1.xpm"
# define E_2	"used_graphics/flag/2.xpm"
# define E_3	"used_graphics/flag/3.xpm"
# define E_4	"used_graphics/flag/4.xpm"
# define E_5	"used_graphics/flag/5.xpm"
# define E_6	"used_graphics/flag/6.xpm"
# define E_7	"used_graphics/flag/7.xpm"
# define E_8	"used_graphics/flag/8.xpm"
# define E_9	"used_graphics/flag/9.xpm"
# define E_10	"used_graphics/flag/10.xpm"
# define E_11	"used_graphics/flag/11.xpm"
# define E_12	"used_graphics/flag/12.xpm"
# define E_13	"used_graphics/flag/13.xpm"
# define E_14	"used_graphics/flag/14.xpm"
# define E_15	"used_graphics/flag/15.xpm"
# define E_16	"used_graphics/flag/16.xpm"
# define E_17	"used_graphics/flag/17.xpm"
# define E_18	"used_graphics/flag/18.xpm"
# define E_19	"used_graphics/flag/19.xpm"
# define E_20	"used_graphics/flag/20.xpm"
# define E_21	"used_graphics/flag/21.xpm"
# define E_22	"used_graphics/flag/22.xpm"
# define E_23	"used_graphics/flag/23.xpm"
# define E_24	"used_graphics/flag/24.xpm"
# define E_25	"used_graphics/flag/25.xpm"
# define E_26	"used_graphics/flag/26.xpm"

/*------------------------ T images ------------------------*/

# define T_1	"used_graphics/enemy/1.xpm"
# define T_2	"used_graphics/enemy/2.xpm"
# define T_3	"used_graphics/enemy/3.xpm"
# define T_4	"used_graphics/enemy/4.xpm"
# define T_5	"used_graphics/enemy/5.xpm"
# define T_6	"used_graphics/enemy/6.xpm"
# define T_7	"used_graphics/enemy/7.xpm"
# define T_8	"used_graphics/enemy/8.xpm"
# define T_9	"used_graphics/enemy/9.xpm"
# define T_10	"used_graphics/enemy/10.xpm"
# define T_11	"used_graphics/enemy/11.xpm"
# define T_12	"used_graphics/enemy/12.xpm"
# define T_13	"used_graphics/enemy/13.xpm"
# define T_14	"used_graphics/enemy/14.xpm"
# define T_15	"used_graphics/enemy/15.xpm"
# define T_16	"used_graphics/enemy/16.xpm"

/*--------------------- simple helpers ---------------------*/

void	initialize(t_mlx *s);
int		free_close(t_mlx *s);
void	free_array(char **map);
void	get_window_w(t_mlx *s, char *file);
void	get_window_h(t_mlx *s, char *file);

/*-------------------- simple helpers 2 --------------------*/

void	turtles_count(t_mlx *s);
void	do_after_move(t_mlx *s);
void	do_before_move(t_mlx *s);
void	before_mlx_init(t_mlx *s, int argc, char *arg);

/*---------------------- map checkers ----------------------*/

int		check_map_var(t_mlx *s);
int		check_map_layout(t_mlx *s);
int		check_map_have(t_mlx *s, char c);
int		check_map_edges(t_mlx *s, char c);

/*------------------------ read map ------------------------*/

void	put_map(t_mlx *s);

/*------------------------- images--------------------------*/

void	add_images(t_mlx *s);

/*----------------------character moves --------------------*/

void	character_move(t_mlx *s, int flag);

void	turtle_walk(t_mlx *s);
int		animation(t_mlx *s);
char	*ft_itoa(int n);

#endif