/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parcoured_path_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:58:32 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 11:20:51 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"
#include "libft.h"

static bool	add_position_node(t_list **path, t_mlx_coords *position)
{
	t_mlx_coords	*new_position;
	t_list			*new_node;

	new_position = malloc(sizeof(t_mlx_coords));
	if (new_position == NULL)
		return (false);
	new_position->x = position->x;
	new_position->y = position->y;
	new_node = ft_lstnew(new_position);
	if (new_node == NULL)
	{
		free(new_position);
		return (false);
	}
	ft_lstadd_front(path, new_node);
	return (true);
}

t_list	*get_parcoured_path(t_stack_path *stack, t_mlx_coords *start)
{
	t_stack_path	*current;
	t_list			*path;

	current = stack;
	path = NULL;
	while (current->position.x != start->x && current->position.y != start->y)
	{
		add_position_node(&path, &current->position);
		current = current->previous;
	}
	ft_lstreverse(&path);
	return (path);
}