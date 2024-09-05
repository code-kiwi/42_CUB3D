/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:16 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 13:25:30 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

#include <math.h>

void	draw_sky_column(t_image *screen, float angle, t_image *texture, \
	int column_index, int diff)
{
	char			*addr;
	char			*color_addr;
	int				index;
	float			texture_pos;
	float			scale_y;
	unsigned int	color;

	index = 0;
	addr = t_mlx_get_pixel(screen, column_index, 0);
	color_addr = t_mlx_get_pixel(texture, angle * (float)texture->width / (PI * 2), texture->height / 3);
	scale_y = (float)texture->height / 3 / WIN_HEIGHT;
	texture_pos = diff * scale_y;
	while (index < WIN_HEIGHT)
	{
		color = *(unsigned int *)(color_addr + \
			(int)texture_pos * texture->line_len);
		*(unsigned int *)addr = color;
		texture_pos += scale_y;
		index++;
		addr += screen->line_len;
	}
}

void	draw_sky(t_game *game)
{
	size_t	index;
	float	column_angle;
	t_image	*screen;
	t_image	*sky_texture;

	index = 0;
	screen = game->mlx.img_buff;
	sky_texture = game->anim[IDX_TXTR_SKY].textures->content;
	while (index < WIN_WIDTH)
	{
		column_angle = atan2f(-game->rays[index].slope.y, game->rays[index].slope.x);
		if (column_angle < 0)
			column_angle += 2 * PI;
		else if (column_angle > 2 * PI)
			column_angle -= 2 * PI;
		draw_sky_column(screen, column_angle, sky_texture, index, -game->player.orientation.y);
		index++;
	}
}