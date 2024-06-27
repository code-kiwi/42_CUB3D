/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_node_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:30:00 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 12:07:55 by brappo           ###   ########.fr       */
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

t_stack_path	*get_node(t_mlx_coords *position, t_stack_path *stack)
{
	while (stack)
	{
		if (position->x == stack->position.x
			&& position->y == stack->position.y)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
	t_stack_path *previous, size_t distance)
{
	t_stack_path	*new_node;
	size_t			start_distance;
	size_t			end_distance;
	size_t			total_cost;

	end_distance = get_end_distance(position, pathfinding->end);
	if (previous != NULL)
		start_distance = previous->start_distance + distance;
	else
		start_distance = 0;
	total_cost = end_distance + start_distance;
	new_node = get_node(position, pathfinding->stack);
	if (new_node != NULL)
	{
		if (new_node->total_cost < total_cost)
			return (true);
		if (new_node->previous != NULL)
			new_node->previous->next = new_node->next;
		if (new_node->next != NULL)
			new_node->next->previous = new_node->previous;
		new_node->previous_tile = previous;
		new_node->end_distance = end_distance;
		new_node->start_distance = start_distance;
		new_node->total_cost = total_cost;
		insert_path_node(&pathfinding->stack, new_node);
		return (true);
	}
	new_node = malloc(sizeof(t_stack_path));
	if (new_node == NULL)
		return (false);
	new_node->position.x = position->x;
	new_node->position.y = position->y;
	new_node->previous_tile = previous;
	new_node->next = NULL;
	new_node->start_distance = start_distance;
	new_node->end_distance = end_distance;
	new_node->total_cost = total_cost;
	insert_path_node(&pathfinding->stack, new_node);
	return (true);
}
