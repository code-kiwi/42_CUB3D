/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:19 by root              #+#    #+#             */
/*   Updated: 2024/06/20 11:40:37y brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#include <math.h>

static float	get_entity_angle(t_vector *sprite_pos, t_vector *player_pos)
{
	float		entity_angle;
	t_vector	entity_direction;

	entity_direction.x = sprite_pos->x - player_pos->x;
	entity_direction.y = sprite_pos->y - player_pos->y;
	entity_angle = atan2f(-entity_direction.y, entity_direction.x);
	return (entity_angle);
}

#include <stdio.h>
void	get_sprite_screen_pos(t_mlx_coords *sprite_screen, t_sprite *sprite,
	t_player *player, float scale)
{
	float		entity_angle;

	entity_angle = player->leftmost_angle;
	entity_angle -= get_entity_angle(&sprite->position, &player->position);
	if (player->orientation > PI / 2 * 3 && entity_angle < PI / 2)
		entity_angle += 2 * PI;
	else if (player->orientation < PI / 2 && entity_angle > PI / 2 * 3)
		entity_angle -= 2 * PI;
	sprite_screen->x = entity_angle * player->pixel_by_angle;
	sprite_screen->x -= sprite->texture->width / 2 * scale;
	sprite_screen->y = WIN_HEIGHT / 2;
	sprite_screen->y -= sprite->texture->height / 2 * scale;
}

void	draw_sprite(t_sprite *sprite, t_player *player, t_image *screen)
{
	t_column	column;
	float		scale;
	float		texture_x_pos;

	scale = 1 / get_distance(&sprite->position, &player->position);
	get_sprite_screen_pos(&column.coords, sprite, player, scale);
	column.start = column.coords.y;
	column.end = column.coords.y + sprite->texture->height * scale;
	if (column.coords.y < 0)
		column.coords.y = 0;
	if (column.end > WIN_HEIGHT)
		column.end = WIN_HEIGHT;
	column.texture_start = column.coords.y - column.start;
	column.texture_column = 0;
	if (column.start < 0)
		column.start = 0;
	column.perceived_height = sprite->texture->height * scale;
	texture_x_pos = 0;
	while (column.texture_column < sprite->texture->width)
	{
		if (column.coords.x > 0 && column.coords.x < screen->width)
			draw_texture_column(screen, &column, sprite->texture);
		texture_x_pos += 1 / scale;
		column.texture_column = texture_x_pos;
		column.coords.x++;
		column.coords.y = column.start;
	}
}
