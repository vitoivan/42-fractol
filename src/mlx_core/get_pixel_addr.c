/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:01 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:00:07 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

char	*get_pixel_addr(t_img *img, int x, int y)
{
	int	bit_depth;
	int	x_cord;
	int	y_cord;

	bit_depth = 8;
	x_cord = x * img->bpp / bit_depth;
	y_cord = y * img->line_length;
	return (img->addr + (x_cord + y_cord));
}
