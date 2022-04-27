/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alia <Alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:24:37 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/04/23 07:11:46 by Alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_close(t_mlx *s)
{
	free_array(s->map);
	// if (!s->t_count)
	// {
	// 	free(s->t_h);
	// 	free(s->t_w);
	// }
	exit(1);
	return (0);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free (map[i++]);
	free(map);
}

void	initialize(t_mlx *s)
{
	int	i;

	i = 0;
	while (i < 5)
		s->urlda[i++] = 0;
	s->window_h = 0;
	s->window_w = 0;
	s->c_count = 0;
	// s->t_count = 0;
	// s->t_move = 0;
	// s->t_h = 0;
	// s->t_w = 0;
	s->p_h = 0;
	s->p_w = 0;
	s->e_h = 0;
	s->e_w = 0;
}

void	get_window_h(t_mlx *s, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	s->map = malloc(s->window_w * sizeof(char *));
	if (!s->map)
		exit(1);
	s->map[s->window_h] = get_next_line(fd);
	while (s->map[s->window_h])
		s->map[++s->window_h] = get_next_line(fd);
	close(fd);
}

void	get_window_w(t_mlx *s, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("%sError: invalid file%s\n", RED, RESET);
		exit(1);
	}
	line = get_next_line(fd);
	if (line == 0)
	{
		printf("%sError: invalid file%s\n", RED, RESET);
		exit(1);
	}
	while (line[s->window_w])
		s->window_w++;
	free(line);
	close(fd);
}
