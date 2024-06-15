/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:49:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/16 15:52:34 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "mlx_api.h"

static void	t_mlx_draw_line_horz(
	t_image *img,
	t_mlx_coords *coords_start,
	t_mlx_coords *coords_end,
	uint32_t color
)
{
	while (coords_start->x < coords_end->x)
	{
		t_mlx_draw_pixel(img, coords_start, color);
		coords_start->x++;
	}
}

static void	t_mlx_draw_line_vert(
	t_image *img,
	t_mlx_coords *coords_start,
	t_mlx_coords *coords_end,
	uint32_t color
)
{
	while (coords_start->y < coords_end->y)
	{
		t_mlx_draw_pixel(img, coords_start, color);
		coords_start->y++;
	}
}

/**
 * @brief Draws a rectangle of the given color, onto the given t_image
 * @param img The image onto we will draw
 * @param coords The starting point coordinates of the line
 * @param size The rectangle's width (size->x) and height (size->y)
 * @param color The color of the rectangle
*/
void	t_mlx_draw_rectangle2(
	t_image *img,
	t_mlx_coords *coords,
	t_mlx_coords *size,
	uint32_t color
)
{
	uint16_t		i;
	t_mlx_coords	start;
	t_mlx_coords	end;

	i = -1;
	if (size->x >= size->y)
	{
		while (++i < size->y)
		{
			start.x = coords->x;
			start.y = coords->y + i;
			end.x = start.x + size->x;
			end.y = start.y + i;
			t_mlx_draw_line_horz(img, &start, &end, color);
		}
		return ;
	}
	while (++i < size->x)
	{
		start.x = coords->x + i;
		start.y = coords->y;
		end.x = start.x + i;
		end.y = start.y + size->y;
		t_mlx_draw_line_vert(img, &start, &end, color);
	}
}
