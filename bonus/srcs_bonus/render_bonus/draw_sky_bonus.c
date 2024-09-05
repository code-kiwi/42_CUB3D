/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:16 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 11:55:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

void	draw_sky_column(t_image *screen, float angle, t_image *texture, \
	int column_index)
{
	char			*addr;
	char			*color_addr;
	size_t			index;
	float			texture_pos;
	float			scale_y;
	unsigned int	color;

	index = 0;
	addr = t_mlx_get_pixel(screen, column_index, 0);
	color_addr = t_mlx_get_pixel(texture, angle * texture->width / PI * 2, 0);
	scale_y = (float)texture->height / WIN_HEIGHT;
	texture_pos = 0;
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
	sky_texture = game->anim[IDX_TXTR_W].textures->content;
	while (index < WIN_WIDTH)
	{
		column_angle = game->rays[index].angle_from_orientation;
		draw_sky_column(screen, column_angle, sky_texture, index);
		index++;
	}
}