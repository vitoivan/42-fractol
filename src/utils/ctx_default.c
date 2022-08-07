/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 11:34:13 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 11:44:05 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	ctx_defaults(t_ctx *ctx)
{
	ctx->fn = NULL;
	ctx->img = NULL;
	ctx->img = NULL;
	ctx->view = NULL;
	ctx->mlx = NULL;
	ctx->theme = 1;
	ctx->window = NULL;
}
