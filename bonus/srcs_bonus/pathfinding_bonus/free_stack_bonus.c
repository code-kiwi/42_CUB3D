/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:59:16 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 12:03:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding_bonus.h"

void	free_stack(t_stack_path *stack)
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
