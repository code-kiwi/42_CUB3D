/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tiles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:34:08 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/16 10:01:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "radar_bonus.h"

static char	get_map_char(t_map *map, int i, int j)
{
	if (
		i < 0 || j < 0
		|| i >= (int)map->lines_count
		|| j >= (int)map->lines_lengths[i]
	)
		return (RADAR_EMPTY_TILE_CHAR);
	else
		return (map->tiles[i][j]);
}

static void	update_tiles_process(
	t_map *map,
	t_radar *radar,
	t_mlx_coords *player_coords
)
{
	int		i;
	int		j;
	int		i_map;
	int		j_map;

	i = 0;
	i_map = player_coords->y - radar->tiles_size / 2;
	while (i < radar->tiles_size)
	{
		j = 0;
		j_map = player_coords->x - radar->tiles_size / 2;
		while (j < radar->tiles_size)
		{
			radar->tiles[i][j] = get_map_char(map, i_map, j_map);
			j++;
			j_map++;
		}
		i++;
		i_map++;
	}
	radar->tiles[radar->tiles_size / 2][radar->tiles_size / 2] \
		= RADAR_PLAYER_CHAR;
}

void	update_tiles(t_map *map, t_radar *radar, t_player *player)
{
	t_mlx_coords	player_coords;

	if (radar == NULL || map == NULL || player == NULL)
		return ;
	player_coords.x = (int) player->position.x;
	player_coords.y = (int) player->position.y;
	update_tiles_process(map, radar, &player_coords);
}