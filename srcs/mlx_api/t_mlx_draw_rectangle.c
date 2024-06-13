/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:29:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "mlx_api.h"

/**
 * @brief Draws a rectangle of the given color, onto the given t_image
 * @param img The image onto we will draw
 * @param coords The starting point coordinates of the line
 * @param size The rectangle's width (size.x) and height (size.y)
 * @param color The color of the rectangle
 * @return true on SUCCESS, false on ERROR
*/
bool	t_mlx_draw_rectangle(
	t_image *img,
	t_mlx_coords coords,
	t_mlx_coords size,
	unsigned int color
)
{
	int	row;

	if (
		img == NULL || coords.x < 0 || coords.x > img->width || coords.y < 0
		|| coords.y > img->height || size.x < 0 || size.y < 0
	)
		return (false);
	row = 0;
	while (row < size.y)
	{
		if (!t_mlx_draw_line(img, coords, \
				(t_mlx_coords){coords.x + size.x, coords.y}, color))
			return (false);
		coords.y++;
		row++;
	}
	return (true);
}
