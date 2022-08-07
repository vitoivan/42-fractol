/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_viewport.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:57:27 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:57:31 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	set_mandelbrot_viewport(t_view *v)
{
	v->zoom = 1.0L;
	if (WIN_WIDTH <= WIN_HEIGHT)
	{
		v->offset_x = 2.0L;
		v->offset_y = 2.0L * (long double)WIN_HEIGHT / (long double)WIN_WIDTH;
	}
	else
	{
		v->offset_x = 2.0L * (long double)WIN_WIDTH / (long double)WIN_HEIGHT;
		v->offset_y = 2.0L;
	}
	v->pixel_size_x = 2.0L * v->offset_x / (long double)WIN_WIDTH;
	v->pixel_size_y = 2.0L * v->offset_y / (long double)WIN_HEIGHT;
}
