/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vertical_move_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:48:40 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 09:33:14 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#include <stdio.h>

static bool	is_grounded(t_player *player)
{
	return (player->camera_y <= PLAYER_HEIGHT * WIN_HEIGHT + GROUND_MIN_DISTANCE);
}

static bool	is_under_ceiling(t_player *player)
{
	return (player->camera_y >= WIN_HEIGHT - CEILING_MIN_DISTANCE);
}

static void	move_vertically(t_player *player, float move)
{
	player->camera_y += move;
	player->camera_y_diff = get_camera_height_diff(player->camera_y);
	player->orientation.y += move;
}

float	get_camera_height_diff(float camera_height)
{
	return (WIN_HEIGHT / 2 - camera_height);
}

void	jump(t_player *player)
{
	if (is_grounded(player))
		player->vertical_move = PLAYER_JUMP_FORCE * WIN_HEIGHT;
}

void	apply_vertical_move(t_player *player, float delta_time)
{
	bool	grounded;

	if (player->vertical_move == 0)
		return ;
	move_vertically(player, player->vertical_move * delta_time);
	grounded = is_grounded(player);
	if (grounded || is_under_ceiling(player))
		player->vertical_move = 0;
	if (!grounded)
		player->vertical_move -= GRAVITY_FORCE * WIN_HEIGHT * delta_time;
}
