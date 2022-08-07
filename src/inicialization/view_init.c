/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:55:06 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:55:12 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

t_view	*view_init(t_ctx *ctx)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	if (!view)
		exit_program(ctx);
	view->offset_x = 0;
	view->offset_y = 0;
	view->zoom = 1;
	ctx->view = view;
	return (view);
}
