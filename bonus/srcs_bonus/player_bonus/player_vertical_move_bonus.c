/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_vertical_move_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:48:40 by brappo            #+#    #+#             */
/*   Updated: 2024/09/05 09:45:42 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#include <stdio.h>

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

bool	is_grounded(t_player *player)
{
	return (player->camera_y <= player->height + GROUND_MIN_DISTANCE);
}

float	get_camera_height_diff(float camera_height)
{
	return (WIN_HEIGHT / 2 - camera_height);
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
		player->vertical_move -= player->gravity_force * delta_time;
}
