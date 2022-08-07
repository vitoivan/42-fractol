/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:54:55 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:54:58 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static void	*ctx_init_mlx(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	if (!ctx->mlx)
		exit_program(ctx);
	return (ctx->mlx);
}

t_ctx	*ctx_init(t_ctx *ctx)
{
	ctx->fn = NULL;
	ctx->theme = 1;
	ctx_init_mlx(ctx);
	window_init(ctx);
	img_init(ctx);
	view_init(ctx);
	return (ctx);
}
