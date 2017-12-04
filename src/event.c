/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:15:40 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/04 20:11:11 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		f_callback_key(void *user_ptr, int key, int action)
{
	t_app	*app;

	app = (t_app*)user_ptr;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		destroy_app(app, EXIT_SUCCESS);
}
