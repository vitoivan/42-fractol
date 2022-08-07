/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:56:11 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:56:53 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static int	get_iterations(t_complex c, t_complex z)
{
	long double	real2;
	long double	img2;
	int			i;

	i = 0;
	real2 = c.real * c.real;
	img2 = c.imaginary * c.imaginary;
	while (i < MAX_ITERATIONS && real2 + img2 <= 4.0)
	{
		c.imaginary = 2 * c.real * c.imaginary + z.imaginary;
		c.real = real2 - img2 + z.real;
		real2 = c.real * c.real;
		img2 = c.imaginary * c.imaginary;
		i++;
	}
	return (i);
}

void	julia(t_ctx *ctx, int x, int y)
{
	t_complex	coordinate;
	int			iterations;

	coordinate = get_coordinate(x, y, ctx);
	ctx->view->coordinate = coordinate;
	iterations = get_iterations(ctx->view->coordinate, ctx->view->c);
	put_pixel_to_img(ctx->img, x, y, ctx->view->colors[iterations]);
}
