/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:59:16 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 14:27:42 by brappo           ###   ########.fr       */
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
