/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:11 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:00:19 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static int	mouse_hooks(int key, int x, int y, t_ctx *ctx)
{
	if (key == MOUSE_SCROLL_UP)
		zoom(ctx, x, y, ctx->fn, 1);
	else if (key == MOUSE_SCROLL_DOWN)
		zoom(ctx, x, y, ctx->fn, -1);
	return (0);
}

static int	theme_hooks(int key, t_ctx *ctx)
{
	if (key == NUM_1)
		ctx->theme = 1;
	else if (key == NUM_2)
		ctx->theme = 2;
	else if (key == NUM_3)
		ctx->theme = 3;
	else if (key == NUM_4)
		ctx->theme = 4;
	else if (key == NUM_5)
		ctx->theme = 5;
	else
		return (0);
	return (1);
}

static int	keyboard_hooks(int key, t_ctx *ctx)
{
	if (key == ESC || key == Q)
		exit_program(ctx);
	else if (key == W || key == UP)
		move(ctx, 0, 0.5L, ctx->fn);
	else if (key == S || key == DOWN)
		move(ctx, 0, -0.5L, ctx->fn);
	else if (key == A || key == LEFT)
		move(ctx, 0.5L, 0, ctx->fn);
	else if (key == D || key == RIGHT)
		move(ctx, -0.5L, 0, ctx->fn);
	else if (theme_hooks(key, ctx))
	{
		colors_init(ctx);
		draw(ctx, ctx->fn);
	}
	return (0);
}

int	register_hooks(t_ctx *ctx)
{
	mlx_key_hook(ctx->window, keyboard_hooks, ctx);
	mlx_mouse_hook(ctx->window, mouse_hooks, ctx);
	mlx_hook(ctx->window, DESTROY, BUTTONPRESS_MASK, exit_program, ctx);
	return (0);
}
