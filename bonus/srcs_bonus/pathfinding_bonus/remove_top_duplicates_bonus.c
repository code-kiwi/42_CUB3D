/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_top_duplicates_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:00:58 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 15:39:45 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

void	remove_top_duplicates(t_stack_path *stack)
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
