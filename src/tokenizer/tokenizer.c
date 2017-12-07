/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:40:56 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/07 22:40:45 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void		f_free_token(char *token_addr)
{
	t_token		*token;

	token = (t_token*)token_addr;
	free(token.value);
}

int				tokenizer_create_from_stream(t_tokenizer *tokenizer,
		t_in_stream *in_stream)
{
	tokenizer->tokens = ft_vector_create(sizeof(t_token), NULL, &f_free_token);
	tokenizer->in_stream = in_stream;
}

int				read_while(t_in_stream *in_stream, int (*f_should_run)(int c),
		t_vector *vector)
{
	t_vector	*vector;
	while (ft_in_stream_peek(in_stream) >= 0
			&& (*f_should_run)(ft_in_stream_peek(in_stream)))
	{
	}
}

int				tokenizer_next(t_tokenizer *tokenizer)
{
	int		c;

	if ((c = ft_in_stream_n(tokenizer->in_stream)) < 0)
		return (c);
	if ()

	return (1);
}
