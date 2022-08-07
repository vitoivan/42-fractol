/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:59:50 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:59:55 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	draw(t_ctx *ctx, void (*fn)(t_ctx *, int, int))
{
	register int	x;
	register int	y;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			(*fn)(ctx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(ctx->mlx, ctx->window, ctx->img->img, 0, 0);
}
