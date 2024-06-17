/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 12:10:36 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d.h"
#include "player.h"
#include "map.h"
#include "libft.h"

bool	t_player_init(t_player *player, t_map *map)
{
	if (player == NULL || map == NULL)
		return (false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	player->position = (t_vector){2.599842f, 3.982844f};
	player->orientation = 0;
	player->turn_direction = 0;
	player->move_speed[0] = 0.1;
	player->move_speed[1] = 0.05;
	player->move_speed[2] = 0.05;
	player->move_speed[3] = 0.05;
	player->rotation_speed = PI / 95;
	ft_memset(player->is_walking, 0, 4 * sizeof(bool));
	return (true);
}
