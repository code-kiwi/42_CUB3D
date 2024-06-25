/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 12:02:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

static bool	is_wall(t_map *map, t_mlx_coords *coords)
{
	if (coords->x < 0 || coords->y < 0
		|| (size_t)coords->y >= map->lines_count
		|| (size_t)coords->x >= map->lines_lengths[coords->y])
	{
		return (true);
	}
	return (map->tiles[coords->y][coords->x] == ID_WALL
			|| map->tiles[coords->y][coords->x] == ID_DOOR_CLOSED);
}

static void	add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map)
{
	t_mlx_coords	coords;
	size_t			x;
	size_t			y;
	t_stack_path	*top;

	top = pathfinding->stack;
	coords.x = top->position.x;
	coords.y = top->position.y;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (!(x == 1 && y == 1)
				&& !is_wall(map, &coords))
			{
				add_path_node(&coords, pathfinding, top);
			}
			x++;
			coords.x++;
		}
		y++;
		coords.y++;
	}
}

t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	pathfinding.stack = NULL;
	pathfinding.end = end;
	pathfinding.start = start;
	while (true)
	{
		add_neighboring_tiles(&pathfinding, map);
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(&pathfinding);
	free_stack(pathfinding.stack);
	return (path);
}
