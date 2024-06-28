/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:09:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 20:53:14 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"

static void	lock_tile(t_pathfinding *pathfinding)
{
	t_stack_path	*new_stack;

	new_stack = pathfinding->stack->next;
	pathfinding->stack->next = pathfinding->locked_tiles;
	pathfinding->locked_tiles = pathfinding->stack;
	pathfinding->stack = new_stack;
}

t_list	*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map)
{
	t_pathfinding	pathfinding;
	t_list			*path;

	if (start == NULL || end == NULL || map == NULL)
		return (NULL);
	if (!t_pathfinding_init(&pathfinding, start, end))
		return (false);
	while (true)
	{
		lock_tile(&pathfinding);
		if (!add_neighboring_tiles(&pathfinding, map))
			return (t_pathfinding_free(&pathfinding), NULL);
		if (pathfinding.stack->position.x == end->x
			&& pathfinding.stack->position.y == end->y)
			break ;
	}
	path = get_parcoured_path(&pathfinding);
	t_pathfinding_free(&pathfinding);
	return (path);
}
