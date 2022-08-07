/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:55:21 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 10:14:16 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	*window_init(t_ctx *ctx)
{
	ctx->window = mlx_new_window(ctx->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!ctx->window)
		exit_program(ctx);
	return (ctx->window);
}
