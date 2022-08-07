/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:39 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:28:35 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	print_help(t_ctx *ctx)
{
	ft_printf(
		"Usage: ./fractol [fractal] [OPTIONS]\n"
		"\n\tAvailable fractals:\n"
		"\t\t- mandelbrot\n"
		"\t\t- julia\n"
		"\tjulia required parameter format:\n"
		"\t\t- julia 0.0:-0.0\n"
		"\n\t Available options:\n"
		"\t\t- mandelbrot:\n"
		"\t\t\t- theme=[1, 2, 3, 4, 5]\n");
	exit_program(ctx);
}
