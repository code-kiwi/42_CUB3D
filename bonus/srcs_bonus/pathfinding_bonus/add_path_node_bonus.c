/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:30:00 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 14:05:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

static size_t	get_end_distance(t_mlx_coords *position, t_mlx_coords *end)
{
	int		x_diff;
	int		y_diff;
	size_t	distance;

	x_diff = end->x - position->x;
	y_diff = end->y - position->y;
	if (x_diff < 0)
		x_diff *= -1;
	if (y_diff < 0)
		y_diff *= -1;
	distance = min(x_diff, y_diff) * 14;
	if (x_diff > y_diff)
		distance += (x_diff - y_diff) * 10;
	else
		distance += (y_diff - x_diff) * 10;
	return (distance);
}

bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
	t_stack_path *previous, int distance)
{
	t_stack_path	*new_node;

	new_node = malloc(sizeof(t_stack_path));
	if (new_node == NULL)
		return (false);
	new_node->position.x = position->x;
	new_node->position.y = position->y;
	new_node->end_distance = get_end_distance(position, pathfinding->end);
	if (previous != NULL)
		new_node->start_distance = previous->start_distance + distance;
	else
		new_node->start_distance = 0;
	new_node->total_cost = new_node->end_distance + new_node->start_distance;
	new_node->previous = previous;
	new_node->next = NULL;
	insert_path_node(&pathfinding->stack, new_node);
	return (true);
}
