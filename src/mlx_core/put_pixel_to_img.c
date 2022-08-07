/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:28 by vivan-de          #+#    #+#             */
/*   Updated: 2022/08/07 09:00:32 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fractol.h"

void	put_pixel_to_img(t_img *img, int x, int y, t_colors color)
{
	char	*dst;

	dst = get_pixel_addr(img, x, y);
	*(unsigned int *)dst = color;
}
