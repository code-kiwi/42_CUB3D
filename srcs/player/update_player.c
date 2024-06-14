/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 18:33:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static void	update_look(t_player *player)
{
	if (player->turn_direction == -1)
		player->orientation += player->rotation_speed;
	else if (player->turn_direction == 1)
		player->orientation -= player->rotation_speed;
}

static void	update_position(t_player *player)
{
	float	new_angle;

	if (player->walk_dir != NONE)
	{
		new_angle = player->orientation + player->walk_dir * PI / 2;
		player->position.x += cos(new_angle) * player->move_speed;
		player->position.y -= sin(new_angle) * player->move_speed;
	}
}

void	update_player(t_player *player)
{
	update_look(player);
	update_position(player);
}