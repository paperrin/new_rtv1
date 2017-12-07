/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:13:58 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/07 21:51:48 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "ft_vector.c"

typedef enum		e_token_type
{
	token_type_read_error = 0,
	token_type_eof = 0,
	token_type_punc = 1,
	token_type_number = 2,
	token_type_var = 3,
}					t_token_type;

typedef struct		s_token
{
	t_token_type	type;
	void			*value;
}					t_token;

typedef struct		s_tokenizer
{
	t_vector		tokens;
	t_in_stream		in_stream;
}					t_tokenizer;

int			tokenizer_create_from_stream(t_tokenizer *tokenizer,
		t_in_stream *in_stream);

int			tokenizer_next(t_tokenizer *tokenizer);

#endif
