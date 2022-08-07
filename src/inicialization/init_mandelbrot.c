/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:06:30 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 10:08:10 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	init_mandelbrot(t_ctx *ctx, int argc, char **argv)
{
	int	theme_nbr;

	if (argc == 3)
	{
		theme_nbr = check_valid_theme(argv[2]);
		if (theme_nbr)
			ctx->theme = theme_nbr;
		else
			print_help();
	}
	set_mandelbrot_viewport(ctx->view);
	ctx->fn = mandelbrot;
}
