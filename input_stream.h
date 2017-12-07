/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stream.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:33:48 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/06 22:34:44 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STREAM_H
# define INPUT_STREAM_H

# define INPUT_STREAM_BUFFER_SIZE 4096

typedef struct			s_input_stream
{
	unsigned int	column;
	unsigned int	line;
	unsigned int	pos;
	char			buffer[INPUT_STREAM_BUFFER_SIZE];
	int				fd;
}						t_input_stream;

t_input_stream			in_stream_create_from_file(const char *path);
t_input_stream			in_stream_create_from_string(const char *str);
const char				*input_stream_peek(t_input_stream *stream);
const char				*input_stream_next(t_input_stream *stream);


#endif
