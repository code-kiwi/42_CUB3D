/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_path_node_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:31:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 11:19:46 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

static int	compare_path_node(t_stack_path *a, t_stack_path *b)
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