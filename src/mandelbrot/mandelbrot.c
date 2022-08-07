/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:57:33 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:59:34 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static int	is_in_mandelbrot(t_complex *c)
{
	t_complex	z;
	long double	real2;
	long double	img2;
	int			i;
	t_complex	tmp;

	if (c->real >= -0.5L && c->real <= 0.2L && c->imaginary >= -0.4L
		&& c->imaginary <= 0.4L)
		return (MAX_ITERATIONS);
	z.real = 0;
	z.imaginary = 0;
	real2 = 0;
	img2 = 0;
	i = 0;
	while (i++ < MAX_ITERATIONS && real2 + img2 <= 4.0)
	{
		tmp = z;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = real2 - img2 + c->real;
		real2 = z.real * z.real;
		img2 = z.imaginary * z.imaginary;
		if (tmp.imaginary == z.imaginary && tmp.real == z.real)
			return (MAX_ITERATIONS);
	}
	return (i);
}

void	mandelbrot(t_ctx *ctx, int x, int y)
{
	t_complex	coordinate;
	int			iterations;

	coordinate = get_coordinate(x, y, ctx);
	ctx->view->coordinate = coordinate;
	iterations = is_in_mandelbrot(&ctx->view->coordinate);
	put_pixel_to_img(ctx->img, x, y, ctx->view->colors[iterations]);
}
