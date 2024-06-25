/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 11:23:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

void	add_neighboring_tiles(t_stack_path **stack, t_mlx_coords *start,
	t_mlx_coords *end, t_map *map)
{
	t_mlx_coords	coords;
	size_t			x;
	size_t			y;
	t_stack_path	*top;

	top = *stack;
	coords.x = top->position.x;
	coords.y = top->position.y;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (!(x == 1 && y == 1)
				&& coords.x > 0 && coords.y > 0
				&& (size_t)coords.y < map->lines_count
				&& (size_t)coords.x < map->lines_lengths[y])
			{
				add_path_node(&coords, stack, start, end, top);
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
	t_stack_path	*stack;
	t_list			*path;

	stack = NULL;
	while (true)
	{
		add_neighboring_tiles(&stack, start, end, map);
		if (stack->position.x == end->x && stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(stack, start);
	return (path);
}
