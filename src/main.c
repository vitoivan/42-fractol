/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:13:05 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:36:22 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	ctx_defaults(&ctx);
	if (argc < 2)
		print_help(&ctx);
	check_fractal_name(&ctx, argv[1]);
	ctx_init(&ctx);
	assign_fractal(&ctx, argc, argv);
	colors_init(&ctx);
	register_hooks(&ctx);
	draw(&ctx, ctx.fn);
	mlx_loop(ctx.mlx);
	return (0);
}
