/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:45 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:44:14 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static int	get_splitted_len(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

static void	set_julia_complex(t_ctx *ctx, char *str)
{
	char		**aux;
	int			aux_len;
	long double	n1;
	long double	n2;

	if (!ft_strchr(str, ':'))
		print_help(ctx);
	aux = ft_split(str, ':');
	aux_len = get_splitted_len(aux);
	if (aux_len != 2)
	{
		free(aux);
		print_help(ctx);
	}
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
			print_help(ctx);
		set_julia_complex(ctx, argv[2]);
		set_julia_viewport(ctx->view);
		ctx->fn = julia;
	}
	if (!ctx->fn)
		exit_program(ctx);
}
