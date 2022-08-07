/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:54 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:12:08 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	zoom(t_ctx *ctx, int mouse_x, int mouse_y, void (*fn)(t_ctx *, int,
			int), int z)
{
	long double	zoom_value;

	zoom_value = pow(2, -z);
	ctx->view->offset_x += mouse_x * ctx->view->pixel_size_x * (ctx->view->zoom
			* zoom_value - ctx->view->zoom);
	ctx->view->offset_y += mouse_y * ctx->view->pixel_size_y * (ctx->view->zoom
			* zoom_value - ctx->view->zoom);
	ctx->view->zoom *= zoom_value;
	draw(ctx, fn);
}
