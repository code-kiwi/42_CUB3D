/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 10:29:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"

#include <unistd.h>

#include <stdio.h>

void	print_stack(t_stack_path *stack, size_t max_index)
{
	size_t	index;

	index = 0;
	printf("\n");
	while (index < max_index && stack)
	{
		printf("%ld, Gcost : %ld, Hcost : %ld, Fcost : %ld, pos : (%d,%d)\n", index, stack->start_distance, stack->end_distance, stack->total_cost, stack->position.x, stack->position.y);
		index++;
	}
}

t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	t_pathfinding_init(&pathfinding, start, end);
	while (true)
	{
		lock_tile(&pathfinding);

		if (!add_neighboring_tiles(&pathfinding, map))
			return (t_pathfinding_free(&pathfinding), NULL);
		// print_stack(pathfinding.stack, 10);
		// sleep(1);
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(&pathfinding);
	t_pathfinding_free(&pathfinding);
	return (path);
}
