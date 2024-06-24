/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 22:55:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

int	get_squared_distance(t_mlx_coords *a, t_mlx_coords *b)
{
	return ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

int	compare_path_node(t_stack_path *a, t_stack_path *b)
{
	int	total_cost_diff;

	total_cost_diff = a->total_cost - b->total_cost;
	if (total_cost_diff == 0)
		return (a->end_distance - b->end_distance);
	return (total_cost_diff);
}

void	insert_path_node(t_stack_path **stack, t_stack_path *new_node)
{
	t_stack_path	*current;
	t_stack_path	*previous;

	if (stack == NULL)
		return ;
	if (*stack == NULL || compare_path_node(new_node, *stack) < 0)
	{
		new_node->next = *stack;
		*stack = new_node;
		return ;
	}
	previous = *stack;
	current = previous->next;
	while (current)
	{
		if (compare_path_node(new_node, current) < 0)
		{
			new_node->next = current;
			previous->next = new_node;
		}
		previous = current;
		current = current->next;
	}
	previous->next = new_node;
}

bool	add_path_node(t_mlx_coords *position, t_stack_path **stack,
	t_mlx_coords *start, t_mlx_coords *end)
{
	t_stack_path	*new_node;

	new_node = malloc(sizeof(t_stack_path));
	if (new_node == NULL)
		return (false);
	new_node->position.x = position->x;
	new_node->position.y = position->y;
	new_node->end_distance = get_squared_distance(position, end);
	new_node->start_distance = get_squared_distance(position, start);
	new_node->total_cost = new_node->end_distance + new_node->start_distance;
	insert_path_node(stack, new_node);
	return (true);
}

void	find_path(t_mlx_coords *start, t_mlx_coords *end)
{
	t_stack_path	*stack;

	stack = NULL;
	while (true)
	{

	}
}
