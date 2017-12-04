/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:36:23 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/04 18:52:24 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include "GLFW/glfw3.h"
# include "ft_printf.h"
# include "ft_math.h"
# include "ft_color.h"
# include "window.h"
# include "image.h"

typedef struct		s_env
{
	t_window		win;
	t_image			draw_buf;
}					t_env;

void				callback_loop(void *user_ptr);

#endif
