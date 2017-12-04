/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:40:23 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/04 20:07:39 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "rt.h"

void		draw_rect(t_image *image, t_vec2i pos, t_vec2i size,
		t_clrf_rgb color)
{
	t_vec2i		off;

	off.y = pos.y;
	while (off.y < pos.y + size.y)
	{
		off.x = pos.x;
		while (off.x < pos.x + size.x)
		{
			image_set_pixel(image, off.x, off.y, color);
			off.x++;
		}
		off.y++;
	}
}

void		callback_loop(void *user_ptr)
{
	t_env	*env;

	env = (t_env*)user_ptr;
	window_clear(&env->win, ft_clrf_rgb(0.2, 0.2, 0.2));
	image_put(&env->draw_buf, 0, 0);
}

void		callback_key(void *user_ptr, int key, int action)
{
	t_env	*env;

	env = (t_env*)user_ptr;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		env->win.should_close = 1;
}

int			main(void)
{
	t_env			env;

	if (!window_create(&env.win, 720, 480, "RT"))
		return (EXIT_FAILURE);
	if (!image_create(&env.draw_buf, 720, 480))
		return (EXIT_FAILURE);
	draw_rect(&env.draw_buf, ft_vec2i(100, 50), ft_vec2i(42, 42),
			ft_clrf_rgb(1, 0.6, 0));
	window_callback_key(&env.win, &callback_key);
	window_callback_loop(&env.win, &callback_loop, &env);
	window_destroy(&env.win);
	image_destroy(&env.draw_buf);
}*/
