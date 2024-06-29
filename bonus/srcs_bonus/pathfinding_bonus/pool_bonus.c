/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:00:45 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 22:08:00 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "pathfinding_bonus.h"

t_stack_path	*get_stack_node(t_pool *pool)
{
	if (pool->object_remaining == 0)
		return (NULL);
	pool->object_remaining--;
	return (pool->objects + pool->object_remaining - 1);
}