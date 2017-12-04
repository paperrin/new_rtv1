/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:49:16 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/27 17:39:56 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define BUFF_SIZE 4096

typedef struct	s_fd
{
	int		fd;
	char	*buff;
	char	*read_pos;
	int		nb_bytes;
}				t_fd;

int				ft_get_next_line(const int fd, char **line);

#endif
