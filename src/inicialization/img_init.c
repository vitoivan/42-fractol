/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:55:03 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:55:04 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

t_img	*img_init(t_ctx *ctx)
{
	ctx->img = (t_img *)malloc(sizeof(t_img));
	if (!ctx->img)
		exit_program(ctx);
	ctx->img->img = mlx_new_image(ctx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!ctx->img->img)
		exit_program(ctx);
	ctx->img->addr = mlx_get_data_addr(ctx->img->img, &ctx->img->bpp,
			&ctx->img->line_length, &ctx->img->endian);
	if (!ctx->img->addr)
		exit_program(ctx);
	return (ctx->img);
}
