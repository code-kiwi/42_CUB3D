/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:19 by root              #+#    #+#             */
/*   Updated: 2024/06/21 16:16:35 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "player_bonus.h"
#include "vector_bonus.h"
#include "sprite_bonus.h"

static float	get_entity_angle(t_vector *sprite_pos, t_vector *player_pos)
{
	float		entity_angle;
	t_vector	entity_direction;

	entity_direction.x = sprite_pos->x - player_pos->x;
	entity_direction.y = sprite_pos->y - player_pos->y;
	entity_angle = atan2f(-entity_direction.y, entity_direction.x);
	if (entity_angle < 0)
		entity_angle += 2 * PI;
	return (entity_angle);
}

static void	get_sprite_screen_pos(t_mlx_coords *sprite_screen, t_sprite *sprite,
	t_player *player, float scale)
{
	float		entity_angle;
	float		relative_angle;

	entity_angle = get_entity_angle(&sprite->position, &player->position);
	relative_angle = player->leftmost_angle - entity_angle;
	if (player->orientation > PI / 2 * 3 && entity_angle < PI / 2)
		relative_angle -= 2 * PI;
	else if (player->orientation < PI / 2 && entity_angle > PI / 2 * 3)
		relative_angle += 2 * PI;
	sprite_screen->x = relative_angle * player->pixel_by_angle;
	sprite_screen->x -= sprite->texture->width / 2 * scale;
	sprite_screen->y = WIN_HEIGHT / 2;
	sprite_screen->y -= sprite->texture->height / 2 * scale;
}

static void	draw_all_columns(
	t_column *column,
	t_sprite *sprite,
	t_image *img,
	t_ray	*rays
)
{
	float	texture_x;

	texture_x = 0;
	if (column->coords.x < 0)
	{
		texture_x -= column->coords.x * sprite->distance;
		column->coords.x = 0;
		column->texture_column = texture_x;
	}
	while (column->texture_column < sprite->texture->width)
	{
		if (column->coords.x >= img->width)
			return ;
		if (rays[column->coords.x].length > sprite->distance)
			draw_texture_column(img, column, sprite->texture);
		texture_x += sprite->distance;
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
	draw_all_columns(&column, sprite, game->mlx.img_buff, game->rays);
}

void	render_all_sprites(t_game *game)
{
	size_t	index;

	index = 0;
	get_sprites_distances(game->sprites, &game->player.position,
		game->sprites_count);
	sort_sprites(game->sprites, game->sprites_count);
	while (index < game->sprites_count)
	{
		draw_sprite(game->sprites[index], game);
		index++;
	}
}
