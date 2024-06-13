/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 12:42:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

bool	t_mlx_draw_pixel(t_image *img, size_t x, size_t y, unsigned int color)
{
	char	*dest;

	if (img == NULL)
		return (false);
	if (x < 0 || x >= img->width || y < 0 || y > img->height)
		return (true);
	dest = img->addr + (y * img->line_len + x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
}
