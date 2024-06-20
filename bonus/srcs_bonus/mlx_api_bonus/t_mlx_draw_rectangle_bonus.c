/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/20 17:03:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "mlx_api_bonus.h"

/**
 * @brief Draws a rectangle of the given color, onto the given t_image
 * @param img The image onto we will draw
 * @param coords The starting point coordinates of the line
 * @param size The rectangle's width (size->x) and height (size->y)
 * @param color The color of the rectangle
*/
void	t_mlx_draw_rectangle(
	t_image *img,
	t_mlx_coords *coords,
	t_mlx_coords *size,
	uint32_t color
)
{
	int		i;
	int		j;
	char	*dest_row;

	j = 0;
	while (j < size->y)
	{
		dest_row = img->addr + ((coords->y + j) * img->line_len) \
			+ (coords->x << 2);
		i = 0;
		while (i < size->x)
		{
			*(uint32_t *)(dest_row + (i << 2)) = color;
			i++;
		}
		j++;
	}
}

void	t_mlx_draw_rect_texture(
	t_image *img,
	t_mlx_coords *coords,
	t_mlx_coords *size,
	t_image *txtr
)
{
	int		i;
	int		j;
	char	*dest_row;

	j = 0;
	while (j < size->y)
	{
		dest_row = img->addr + ((coords->y + j) * img->line_len) \
			+ (coords->x << 2);
		i = 0;
		while (i < size->x)
		{
			*(uint32_t *)(dest_row + (i << 2)) = *(unsigned int *) \
				(t_mlx_get_pixel(txtr, i % txtr->width, j % txtr->height));
			i++;
		}
		j++;
	}
}
