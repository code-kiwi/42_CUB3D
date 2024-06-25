/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:30:00 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 11:37:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

static int	get_squared_distance(t_mlx_coords *a, t_mlx_coords *b)
{
	return ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
	t_stack_path *previous)
{
	t_stack_path	*new_node;

	new_node = malloc(sizeof(t_stack_path));
	if (new_node == NULL)
		return (false);
	new_node->position.x = position->x;
	new_node->position.y = position->y;
	new_node->end_distance = get_squared_distance(position, pathfinding->end);
	new_node->start_distance = get_squared_distance(position,
			pathfinding->start);
	new_node->total_cost = new_node->end_distance + new_node->start_distance;
	new_node->previous = previous;
	insert_path_node(&pathfinding->stack, new_node);
	return (true);
}
