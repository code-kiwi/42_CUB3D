/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/09/04 14:18:58 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/// @brief Draw a wall with a texture
/// @param screen The screen to draw to.
/// @param column The column data to draw
/// @param texture The texture to apply to the wall
/// @param distance THe distance of the wall from teh player
void	draw_texture_column(t_image *screen, t_column *column, t_image *texture,
	float distance)
{
	char			*color_addr;
	float			scale_y;
	char			*addr;
	float			texture_pos;
	unsigned int	color;

	scale_y = texture->height / column->perceived_height;
	addr = screen->addr + (column->coords.y * screen->line_len \
		+ column->coords.x * screen->bpp_factor);
	// addr = t_mlx_get_pixel(screen, column->coords.x, column->coords.y);
	color_addr = texture->addr + column->texture_x * screen->bpp_factor;
	texture_pos = column->texture_start * scale_y;
	while (column->coords.y < column->ranged_end)
	{
		color = *(unsigned int *)(color_addr + \
			(int)texture_pos * texture->line_len);
		if (color != 0xFF000000)
		{
			multiply_color(&color, 1 - distance / MAX_VISION_DISTANCE);
			*(unsigned int *)addr = color;
		}
		addr += screen->line_len;
		column->coords.y++;
		texture_pos += scale_y;
	}
}
