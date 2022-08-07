/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:57:00 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:57:18 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static t_rgb	set_color(int color)
{
	t_rgb	rgb;

	rgb.r = (color & 0xFF0000) >> 16;
	rgb.g = (color & 0x00FF00) >> 8;
	rgb.b = (color & 0x0000FF);
	return (rgb);
}

static int	lerp(double a, double b, double t)
{
	if (a == b)
		return (a);
	return ((int)((double)a + (b - a) * t));
}

static t_rgb	interp(t_rgb c1, t_rgb c2, double p)
{
	t_rgb	color;

	color.r = lerp(c1.r, c2.r, p);
	color.g = lerp(c1.g, c2.g, p);
	color.b = lerp(c1.b, c2.b, p);
	return (color);
}

static void	set_gradient_colors(t_rgb gradient_colors[6])
{
	gradient_colors[0] = set_color(0xffffff);
	gradient_colors[1] = set_color(0x6a00ff);
	gradient_colors[2] = set_color(0xffffff);
	gradient_colors[3] = set_color(0xab0101);
	gradient_colors[4] = set_color(0x00F0FF);
	gradient_colors[5] = set_color(0x270138);
}

int	get_colors(int i, t_ctx *ctx)
{
	double	p;
	t_rgb	gradient[6];
	t_rgb	color;
	int		max_colors;
	int		out;

	if (i == MAX_ITERATIONS)
		return (0x000000);
	set_gradient_colors(gradient);
	max_colors = 6;
	p = (double)i / (double)MAX_ITERATIONS;
	p = fmod(p, 1.0f / max_colors) * max_colors;
	color = interp(gradient[ctx->theme - 1], gradient[ctx->theme], 1 - p);
	out = 255 << 24;
	out |= (int)(color.r) << 16;
	out |= (int)(color.g) << 8;
	out |= (int)(color.b);
	return (out);
}
