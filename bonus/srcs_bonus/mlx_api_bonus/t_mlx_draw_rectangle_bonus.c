/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/28 11:55:05 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

static bool	t_mlx_is_rect_valid(t_mlx_coords *coords, t_mlx_coords *size)
{
	return (
		coords->x >= 0 && coords->x < WIN_WIDTH
		&& coords->y >= 0 && coords->y < WIN_HEIGHT
		&& size->x > 0 && size->y > 0
		&& coords->x + size->x <= WIN_WIDTH
		&& coords->y + size->y <= WIN_HEIGHT
	);
}

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

	if (!t_mlx_is_rect_valid(coords, size))
	{
		error_print(ERR_RECTANGLE);
		return ;
	}
	j = 0;
	while (j < size->y)
	{
		dest_row = img->addr + ((coords->y + j) * img->line_len) \
			+ (coords->x * img->bpp_factor);
		i = 0;
		while (i < size->x)
		{
			*(uint32_t *)(dest_row + (i * img->bpp_factor)) = color;
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
	int			i;
	int			j;
	char		*dest_row;
	uint32_t	color;

	if (!t_mlx_is_rect_valid(coords, size))
		return (error_print(ERR_RECTANGLE));
	j = 0;
	while (j < size->y)
	{
		dest_row = img->addr + ((coords->y + j) * img->line_len) \
			+ (coords->x * img->bpp_factor);
		i = 0;
		while (i < size->x)
		{
			color = *(uint32_t *)t_mlx_get_pixel(txtr, i % txtr->width, \
				j % txtr->height);
			if (color != 0xFF000000)
				*(uint32_t *)(dest_row + (i * img->bpp_factor)) = color;
			i++;
		}
		j++;
	}
}
