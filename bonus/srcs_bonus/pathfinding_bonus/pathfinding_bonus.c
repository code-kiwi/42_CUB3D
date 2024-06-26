/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 15:24:06 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"

#include <unistd.h>

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

bool	is_locked(t_mlx_coords *position, t_stack_path *locked_tiles)
{
	t_stack_path	*current;

	current = locked_tiles;
	while (current)
	{
		if (position->x == current->position.x
			&& position->y == current->position.y)
			return (true);
		current = current->next;
	}
	return (false);
}	

#include <stdio.h>

static bool	add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map)
{
	t_mlx_coords	coords;
	int				x;
	int				y;
	t_stack_path	*top;

	top = pathfinding->locked_tiles;
	y = -1;
	while (y < 2)
	{
		x = -1;
		while (x < 2)
		{
			coords.x = top->position.x + x;
			coords.y = top->position.y + y;
			if (!is_locked(&coords, pathfinding->locked_tiles)
				&& !is_wall(map, &coords))
			{
				if (!add_path_node(&coords, pathfinding, top))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

void	print_stack(t_stack_path *stack, size_t max_index)
{
	size_t	index;

	index = 0;
	printf("\n");
	while (stack && index < max_index)
	{
		printf("index : %ld, pos : (%d,%d), Hcost : %ld, Gcost : %ld, Fcost : %ld\n", index, stack->position.x, stack->position.y, stack->end_distance, stack->start_distance, stack->total_cost);
		stack = stack->next;
		index++;
	}
}

static void	lock_tile(t_pathfinding *pathfinding)
{
	t_stack_path	*new_stack;

	new_stack = pathfinding->stack->next;
	pathfinding->stack->next = pathfinding->locked_tiles;
	pathfinding->locked_tiles = pathfinding->stack;
	pathfinding->stack = new_stack;
}

t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	pathfinding.stack = NULL;
	pathfinding.locked_tiles = NULL;
	pathfinding.end = end;
	pathfinding.start = start;
	add_path_node(start, &pathfinding, NULL);
	while (true)
	{
		lock_tile(&pathfinding);
		if (!add_neighboring_tiles(&pathfinding, map))
		{
			free_stack(pathfinding.locked_tiles);
			free_stack(pathfinding.stack);
			return (NULL);
		}
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
		print_stack(pathfinding.stack, 10);
		sleep(1);
	}
	path = get_parcoured_path(&pathfinding);
	free_stack(pathfinding.stack);
	free_stack(pathfinding.locked_tiles);
	return (path);
}
