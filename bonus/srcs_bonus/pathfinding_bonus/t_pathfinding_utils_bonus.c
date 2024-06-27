/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pathfinding_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:59:16 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 13:37:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

static void	free_stack(t_stack_path *stack)
{
	t_stack_path	*previous;

	if (stack == NULL)
		return ;
	while (stack)
	{
		previous = stack;
		stack = stack->next;
		free(previous);
	}
}

void	t_pathfinding_free(t_pathfinding *pathfinding)
{
	free_stack(pathfinding->locked_tiles);
	free_stack(pathfinding->stack);
}

void	t_pathfinding_init(t_pathfinding *pathfinding, t_mlx_coords *start,
	t_mlx_coords *end)
{
	pathfinding->stack = NULL;
	pathfinding->locked_tiles = NULL;
	pathfinding->end = end;
	pathfinding->start = start;
	add_path_node(start, pathfinding, NULL, 0);
}

t_stack_path	*search_in_stack(t_stack_path *stack, t_mlx_coords *position)
{
	while (stack)
	{
		if (stack->position.x == position->x
			&& stack->position.y == position->y)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
