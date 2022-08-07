/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:45 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:22:10 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static void	set_julia_complex(t_ctx *ctx, char *str)
{
	char		**aux;
	long double	n1;
	long double	n2;

	if (!ft_strchr(str, ':'))
		print_help();
	aux = ft_split(str, ':');
	n1 = atof(aux[0]);
	n2 = atof(aux[1]);
	free(aux);
	ctx->view->c.real = n1;
	ctx->view->c.imaginary = n2;
}

void	assign_fractal(t_ctx *ctx, int argc, char **argv)
{
	char	*name;

	name = argv[1];
	if (!ft_strcmp(name, "mandelbrot"))
		init_mandelbrot(ctx, argc, argv);
	else if (!ft_strcmp(name, "julia"))
	{
		if (argc < 3)
			print_help();
		set_julia_complex(ctx, argv[2]);
		set_julia_viewport(ctx->view);
		ctx->fn = julia;
	}
	if (!ctx->fn)
		exit_program(ctx);
}
