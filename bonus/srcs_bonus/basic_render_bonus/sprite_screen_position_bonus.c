/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_screen_position_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:08:17 by root              #+#    #+#             */
/*   Updated: 2024/09/04 09:40:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "sprite_bonus.h"
#include "cub3d_bonus.h"

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

void	get_sprite_screen_pos(t_mlx_coords *sprite_screen, t_sprite *sprite,
	t_game *game, float scale)
{
	float		entity_angle;
	float		relative_angle;
	t_player	*player;
	int			height_offset;

	player = &game->player;
	height_offset = get_height_offset(sprite->height * scale, \
		game->player.camera_y_diff);
	entity_angle = get_entity_angle(&sprite->position, &player->position);
	relative_angle = player->leftmost_angle - entity_angle;
	if (player->orientation.x > PI / 2 * 3 && entity_angle < PI / 2)
		relative_angle -= 2 * PI;
	else if (player->orientation.x < PI / 2 && entity_angle > PI / 2 * 3)
		relative_angle += 2 * PI;
	sprite_screen->x = relative_angle * player->pixel_by_angle;
	sprite_screen->x -= sprite->height / 2 * scale;
	sprite_screen->y = WIN_HEIGHT / 2;
	sprite_screen->y -= sprite->height / 2 * scale;
	if (sprite->on_ground)
		sprite_screen->y += (WIN_HEIGHT - sprite->height) / 2 * scale;
	else if (sprite->on_ceiling)
		sprite_screen->y -= (WIN_HEIGHT - sprite->height) / 2 * scale;
	sprite_screen->y += game->player.orientation.y;
	sprite_screen->y += height_offset;
}

bool	is_sprite_aimed(t_sprite *sprite, int left_x)
{
	int		aimed_column;
	float	height_ratio;
	t_image	*texture;
	char	*color;

	if (sprite == NULL)
		return (false);
	if (left_x > WIN_WIDTH / 2)
		return (false);
	if (left_x + sprite->height / sprite->distance < WIN_WIDTH / 2)
		return (false);
	texture = sprite->texture->content;
	height_ratio = sprite->distance * texture->width / sprite->height;
	aimed_column = (WIN_WIDTH / 2 - left_x) * height_ratio;
	color = t_mlx_get_pixel(texture, aimed_column, texture->height / 2);
	return (*(unsigned int *)color != 0xFF000000);
}
