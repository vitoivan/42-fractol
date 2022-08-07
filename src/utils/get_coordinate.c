/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:26 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:12:27 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static long double	get_x(t_view *v, int x)
{
	return ((x * v->pixel_size_x * v->zoom) - v->offset_x);
}

static long double	get_y(t_view *v, int y)
{
	return ((y * v->pixel_size_y * v->zoom) - v->offset_y);
}

t_complex	get_coordinate(int x, int y, t_ctx *ctx)
{
	t_complex	c;

	c.real = get_x(ctx->view, x);
	c.imaginary = get_y(ctx->view, y);
	return (c);
}
