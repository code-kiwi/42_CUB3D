/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_path_node_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:31:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 11:16:20 by brappo           ###   ########.fr       */
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

static void	remove_top_duplicate(t_stack_path *stack)
{
	t_stack_path	*top;
	t_stack_path	*previous;
	t_stack_path	*temp;

	if (stack == NULL)
		return ;
	top = stack;
	previous = stack;
	stack = stack->next;
	while (stack && stack->total_cost == top->total_cost)
	{
		if (top->position.x == stack->position.x
			&& top->position.y == stack->position.y)
		{
			previous->next = stack->next;
			temp = stack;
			stack = stack->next;
			free(temp);
			continue ;
		}
		previous = stack;
		stack = stack->next;
	}
}

void	insert_path_node(t_stack_path **stack, t_stack_path *new_node)
{
	t_stack_path	*current;
	t_stack_path	*previous;

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
			return ;
		}
		previous = current;
		current = current->next;
	}
	previous->next = new_node;
	remove_top_duplicate(new_node);
}
