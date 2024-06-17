/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 11:39:38 by codekiwi         ###   ########.fr       */
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
