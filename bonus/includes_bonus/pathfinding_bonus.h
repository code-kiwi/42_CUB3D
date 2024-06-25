/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:32:49 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 11:35:49 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_BONUS_H
# define PATHFINDING_BONUS_H

# include <stdlib.h>

# include "mlx_api_bonus.h"

typedef struct s_path_stack		t_stack_path;
typedef struct s_pathfinding	t_pathfinding;

struct	s_path_stack
{
	t_mlx_coords	position;
	size_t			start_distance;
	size_t			end_distance;
	size_t			total_cost;
	t_stack_path	*next;
	t_stack_path	*previous;
};

struct	s_pathfinding
{
	t_stack_path	*stack;
	t_mlx_coords	*start;
	t_mlx_coords	*end;
};

bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
			t_stack_path *previous);
void	insert_path_node(t_stack_path **stack, t_stack_path *new_node);
t_list	*get_parcoured_path(t_pathfinding *pathfinding);

#endif // !PATHFINDING_BONUS_H