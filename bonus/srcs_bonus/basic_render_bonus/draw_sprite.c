/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:19 by root              #+#    #+#             */
/*   Updated: 2024/06/19 21:41:48 by root             ###   ########.fr       */
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
	if (entity_angle < 0)
		entity_angle += 2 * PI;
	return (entity_angle);
}

#include <stdio.h>
void	get_sprite_screen_pos(t_mlx_coords *sprite_screen, t_vector *sprite_pos,
	t_player *player)
{
	float		entity_angle;

	entity_angle = player->leftmost_angle;
	entity_angle -= get_entity_angle(sprite_pos, &player->position);
	if (player->orientation > PI / 2 * 3 && entity_angle < PI / 2)
		entity_angle += 2 * PI;
	else if (player->orientation < PI / 2 && entity_angle > PI / 2 * 3)
		entity_angle -= 2 * PI;
	sprite_screen->x = entity_angle * player->pixel_by_angle;
	sprite_screen->y = WIN_HEIGHT / 2;
}

void	draw_sprite_column()
{

}


void	draw_sprite(t_sprite *sprite, t_player *player)
{
	t_mlx_coords	sprite_screen;
	float			scale;

	get_sprite_screen_pos(&sprite_screen, &sprite->position, player);
	scale = 1 / get_distance(&sprite->position, &player->position);
	printf("scale : %f\n", scale);
	printf("sprite screen : (%d,%d)\n", sprite_screen.x, sprite_screen.y);
}
