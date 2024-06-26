/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 14:33:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>

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

void	print_stack(t_stack_path *stack, size_t max_index)
{
	size_t	index;

	index = 0;
	printf("\n");
	while (stack && index < max_index)
	{
		printf("index : %ld, pos : (%d,%d), Hcost : %ld, Gcost : %ld, Fcost : %ld\n", index, stack->position.x, stack->position.y, stack->end_distance, stack->start_distance, stack->total_cost);
		stack = stack->next;
		index++;
	}
}

t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	pathfinding.stack = NULL;
	pathfinding.locked_tiles = NULL;
	pathfinding.end = end;
	pathfinding.start = start;
	add_path_node(start, &pathfinding, NULL, 0);
	while (true)
	{
		remove_top_duplicate(pathfinding.stack);
		lock_tile(&pathfinding);
		if (!add_neighboring_tiles(&pathfinding, map))
		{
			t_pathfinding_free(&pathfinding);
			return (NULL);
		}
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(&pathfinding);
	t_pathfinding_free(&pathfinding);
	return (path);
}
