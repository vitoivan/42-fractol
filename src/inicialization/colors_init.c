/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:54:31 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 08:54:45 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	colors_init(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		ctx->view->colors[i] = get_colors(i, ctx);
		i++;
	}
}
