/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fractal_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:13 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:31:18 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	check_fractal_name(t_ctx *ctx, char *name)
{
	if (ft_strcmp(name, "mandelbrot") && ft_strcmp(name, "julia"))
		print_help(ctx);
}
