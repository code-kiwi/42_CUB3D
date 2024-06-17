/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 14:45:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d.h"
#include "player.h"
#include "map.h"
#include "libft.h"

static void	set_player_orientation(t_player *player, t_map *map)
{
	char			*directions;
	int				angle;
	t_mlx_coords	coords;

	coords.x = player->position.x;
	coords.y = player->position.y;
	directions = "ENWS";
	angle = ft_strchr(directions, map->tiles[coords.y][coords.x]) - directions;
	angle *= PI / 2;
	player->orientation = angle;
}

static bool	find_player_position(t_map *map, t_player *player)
{
	t_mlx_coords	coords;
	bool			found_player;

	coords.y = 0;
	found_player = false;
	while ((size_t)coords.y < map->lines_count)
	{
		coords.x = 0;
		while ((size_t)coords.x < map->lines_lengths[coords.y])
		{
			if (ft_strchr("NWSE", map->tiles[coords.y][coords.x]))
			{
				if (found_player)
					return (error_print(ERR_MULTIPLE_PLAYERS), false);
				found_player = true;
				t_vector_init(&player->position, coords.x, coords.y);
			}
			coords.x++;
		}
		coords.y++;
	}
	if (found_player == false)
		return (error_print(ERR_MISSING_PLAYER), false);
	return (true);
}

bool	t_player_init(t_player *player, t_map *map)
{
	if (player == NULL || map == NULL)
		return (false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	if (!find_player_position(map, player))
		return (false);
	set_player_orientation(player, map);
	player->position.x += 0.5;
	player->position.y += 0.5;
	player->turn_direction = 0;
	player->move_speed[0] = 0.1;
	player->move_speed[1] = 0.05;
	player->move_speed[2] = 0.05;
	player->move_speed[3] = 0.05;
	player->rotation_speed = PI / 95;
	ft_memset(player->is_walking, 0, 4 * sizeof(bool));
	return (true);
}
