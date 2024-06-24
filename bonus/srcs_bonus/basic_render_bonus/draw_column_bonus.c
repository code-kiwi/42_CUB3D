/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/06/24 10:10:51 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "door_bonus.h"

void	draw_texture_column(t_image *screen, t_column *column, t_image *texture)
{
	char			*color_addr;
	float			scale_y;
	char			*addr;
	float			texture_pos;
	unsigned int	color;

	scale_y = texture->height / column->perceived_height;
	addr = screen->addr + (column->coords.y * screen->line_len \
		+ column->coords.x * screen->bpp_factor);
	color_addr = texture->addr + column->texture_column * screen->bpp_factor;
	texture_pos = column->texture_start * scale_y;
	while (column->coords.y < column->end)
	{
		color = *(unsigned int *)(color_addr + \
			(int)texture_pos * texture->line_len);
		if (color != 0xFF000000)
			*(unsigned int *)addr = color;
		addr += screen->line_len;
		column->coords.y++;
		texture_pos += scale_y;
	}
}
