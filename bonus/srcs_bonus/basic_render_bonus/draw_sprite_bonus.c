/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:19 by root              #+#    #+#             */
/*   Updated: 2024/07/11 11:11:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "player_bonus.h"
#include "vector_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

static void	draw_all_columns(
	t_column *column,
	t_sprite *sprite,
	t_image *img,
	t_ray	*rays
)
{
	float	texture_x;
	t_image	*texture;
	float	distance;

	texture = sprite->animation->content;
	texture_x = 0;
	if (column->coords.x < 0)
	{
		texture_x -= column->coords.x * sprite->distance \
			* texture->width / sprite->height;
		column->coords.x = 0;
		column->texture_column = texture_x;
	}
	while (column->texture_column < texture->width)
	{
		if (column->coords.x >= img->width)
			return ;
		distance = rays[column->coords.x].length;
		if (distance > sprite->distance)
			draw_texture_column(img, column, texture, sprite->distance);
		texture_x += sprite->distance * texture->width / sprite->height;
		column->texture_column = texture_x;
		column->coords.x++;
		column->coords.y = column->start;
	}
}

static void	draw_sprite(t_sprite *sprite, t_game *game)
{
	t_column	column;
	float		scale;

	scale = 1 / sprite->distance;
	get_sprite_screen_pos(&column.coords, sprite, &game->player, scale);
	column.start = column.coords.y;
	column.end = column.coords.y + sprite->height * scale;
	if (column.coords.y < 0)
		column.coords.y = 0;
	if (column.end > WIN_HEIGHT)
		column.end = WIN_HEIGHT;
	column.texture_start = column.coords.y - column.start;
	column.texture_column = 0;
	if (column.start < 0)
		column.start = 0;
	column.perceived_height = sprite->height * scale;
	if (is_sprite_aimed(sprite, column.coords.x))
	{
		game->player.aimed_sprite = sprite;
	}
	draw_all_columns(&column, sprite, game->mlx.img_buff, game->rays);
}

void	render_all_sprites(t_game *game)
{
	t_list	*current;

	if (!game->sprites)
		return ;
	game->player.aimed_sprite = NULL;
	get_sprites_distances(game->sprites, &game->player.position);
	sort_list(game->sprites, compare_sprite_distance);
	current = game->sprites;
	while (current != NULL)
	{
		draw_sprite(current->content, game);
		current = current->next;
	}
}
