/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:32:48 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/06 16:07:11 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		create_app(t_app *app, unsigned int width, unsigned int height
		, char *title)
{
	if (!window_create(&app->win, width, height, title))
		return (0);
	if (!image_create(&app->draw_buf, width, height))
	{
		window_destroy(&app->win);
		return (0);
	}
	return (1);
}

void			destroy_app(t_app *app, int exit_code)
{
	window_destroy(&app->win);
	image_destroy(&app->draw_buf);
	exit(exit_code);
}

void			f_callback_loop(void *user_ptr)
{
	t_app	*app;

	app = (t_app*)user_ptr;
	window_clear(&app->win, ft_clrf_rgb(0, 0, 0));
	render(app);
	window_swap_buffers(&app->win);
}

int				main(void)
{
	t_app		app;

	if (!create_app(&app, WIN_WIDTH, WIN_HEIGHT, "RTv1 paperrin"))
		return (EXIT_FAILURE);
	window_callback_key(&app.win, &f_callback_key);
	f_callback_loop(&app);
	window_loop(&app.win, &app);
	destroy_app(&app, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
