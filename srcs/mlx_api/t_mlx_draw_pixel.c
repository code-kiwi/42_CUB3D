/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/16 19:13:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

/**
 * @brief Draws a pixel a the given coordinates of the given color onto img
 * @param img The image onto the pixel will be drawn
 * @param coords The pixel coordinates
 * @param color The color of the pixel
 * @return true on SUCCESS, false on ERROR
 * @note If the coordinate is not valid onto the image, the nothing happens
*/
bool	t_mlx_draw_pixel(t_image *img, t_mlx_coords *coords, unsigned int color)
{
	char	*dest;

	dest = img->addr + (coords->y * img->line_len + coords->x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
}

/**
 * @return The pixel adresses
 * @param x The column of the pixel
 * @param y The row of the pixel
 */
char	*t_mlx_get_pixel(t_image *image, size_t x, size_t y)
{
	return (image->addr + x * image->line_len + y * (image->bpp / 8));
}

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
