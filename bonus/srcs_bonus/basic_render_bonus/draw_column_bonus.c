/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:55 by root              #+#    #+#             */
/*   Updated: 2024/06/20 11:22:33 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"

void	draw_texture_column(t_image *screen, t_column *column, t_image *texture)
{
	char	*color;
	float	scale_y;
	char	*addr;
	float	texture_pos;

	scale_y = texture->height / column->perceived_height;
	addr = screen->addr + (column->coords.y * screen->line_len \
		+ column->coords.x * screen->bpp / 8);
	color = texture->addr + column->texture_column * (screen->bpp / 8);
	texture_pos = column->texture_start * scale_y;
	while (column->coords.y < column->end)
	{
		*(unsigned int *)addr = *(unsigned int *)(color + \
			(int)texture_pos * texture->line_len);
		addr += screen->line_len;
		column->coords.y++;
		texture_pos += scale_y;
	}
}
