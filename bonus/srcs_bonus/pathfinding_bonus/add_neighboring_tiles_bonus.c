/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_neighboring_tiles_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:30:42 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 15:39:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"
#include "cub3d_bonus.h"

static int	distance(int x, int y)
{
	if (x != 0 && y != 0)
		return (14);
	return (10);
}

bool	add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map)
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
				&& is_walkable(map, &coords))
			{
				if (!add_path_node(&coords, pathfinding, top, distance(x, y)))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
