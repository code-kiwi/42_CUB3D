/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_argb_color_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:39:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/28 15:37:05 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

bool	set_color(unsigned int *result, int r, int g, int b)
{
	t_argb_color	color;

	if (r < 0 || g < 0 || b < 0
		|| r > 255 || g > 255 || b > 255)
		return (false);
	color.rgba.a = 255;
	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	*result = color.val;
	return (true);
}

void	multiply_color(unsigned int *color, float factor)
{
	int	r;
	int	g;
	int	b;

	if (factor < 0)
	{
		*color = 0xFF000000;
		return ;
	}
	b = (*color) & 0xFF;
	g = (*color >> 8) & 0xFF;
	r = (*color >> 16) & 0xFF;
	set_color(color, r * factor, g * factor, b * factor);
}
