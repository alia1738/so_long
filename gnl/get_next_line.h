/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:03:43 by aalsuwai          #+#    #+#             */
/*   Updated: 2021/12/10 19:30:00 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

typedef struct s_return_remain
{
	char	*ret;
	char	*rem;
}	t_return_remain;

void	ft_free(char *s, char *ss, char *sss);
int		s_len(char *s);
int		new_line_check(char *s);
void	*ft_calloc(ssize_t count, ssize_t size);
char	*get_next_line(int fd);

#endif
