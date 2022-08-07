/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:11:34 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:11:35 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

int	move(t_ctx *ctx, long double x, long double y, void (*fn)(t_ctx *, int,
			int))
{
	ctx->view->offset_x += x * ctx->view->zoom;
	ctx->view->offset_y += y * ctx->view->zoom;
	draw(ctx, fn);
	return (0);
}
