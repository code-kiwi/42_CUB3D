/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 11:50:23 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

/**
 * @brief Draws a pixel a the given coordinates of the given color onto img
 * @param img The image onto the pixel will be drawn
 * @param coords The pixel coordinates as a pointer
 * @param color The color of the pixel
*/
void	t_mlx_draw_pixel(
	t_image *img,
	t_mlx_coords *coords,
	uint32_t color
)
{
	*(uint32_t *)(img->addr + \
		(coords->y * img->line_len + (coords->x << 2))) = color;
}

/**
 * @brief Draws a pixel a the given coordinates of the given color onto img
 * @param img The image onto the pixel will be drawn
 * @param coords The pixel coordinates as a pointer
 * @param color The color of the pixel
 * @note SECURED -> if the coordinate is not valid, nothing happens
*/
void	t_mlx_draw_pixel_secured(
	t_image *img,
	t_mlx_coords *coords,
	uint32_t color)
{
	char	*dest;

	if (
		img == NULL
		|| coords->x < 0 || coords->x >= img->width
		|| coords->y < 0 || coords->y > img->height
	)
		return ;
	dest = img->addr + (coords->y * img->line_len + coords->x * img->bpp / 8);
	*(uint32_t *) dest = color;
}
