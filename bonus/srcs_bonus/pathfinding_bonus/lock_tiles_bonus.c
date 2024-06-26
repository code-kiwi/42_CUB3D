/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_tiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:53:30 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 13:54:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

void	lock_tile(t_pathfinding *pathfinding)
{
	t_stack_path	*new_stack;

	new_stack = pathfinding->stack->next;
	pathfinding->stack->next = pathfinding->locked_tiles;
	pathfinding->locked_tiles = pathfinding->stack;
	pathfinding->stack = new_stack;
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
