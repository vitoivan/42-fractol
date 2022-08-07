/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:18 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:37:59 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

static void	free_if_exist(void *ptr)
{
	if (ptr && ptr != NULL)
		free(ptr);
}

static void	clear_ctx(t_ctx *ctx)
{
	free_if_exist(ctx->view);
	if (ctx->img)
	{
		mlx_destroy_image(ctx->mlx, ctx->img->img);
		free_if_exist(ctx->img);
	}
	if (ctx->window)
		mlx_destroy_window(ctx->mlx, ctx->window);
	free_if_exist(ctx->mlx);
}

int	exit_program(t_ctx *ctx)
{
	clear_ctx(ctx);
	exit(EXIT_FAILURE);
	return (0);
}
