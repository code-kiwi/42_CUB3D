/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:32:49 by brappo            #+#    #+#             */
/*   Updated: 2024/06/26 15:46:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_BONUS_H
# define PATHFINDING_BONUS_H

# define NEIGHBORS_COUNT 4

# include <stdlib.h>

# include "mlx_api_bonus.h"

typedef struct s_path_stack		t_stack_path;
typedef struct s_pathfinding	t_pathfinding;
typedef struct s_list			t_list;
typedef struct s_map			t_map;

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
	t_stack_path	*locked_tiles;
};

void	insert_path_node(t_stack_path **stack, t_stack_path *new_node);
t_list	*get_parcoured_path(t_pathfinding *pathfinding);
bool	add_path_node(t_mlx_coords *position, t_pathfinding *pathfinding,
			t_stack_path *previous, size_t distance);
bool	is_locked(t_mlx_coords *position, t_stack_path *locked_tiles);
void	lock_tile(t_pathfinding *pathfinding);
void	t_pathfinding_free(t_pathfinding *pathfinding);
void	t_pathfinding_init(t_pathfinding *pathfinding, t_mlx_coords *start,
			t_mlx_coords *end);
void	remove_top_duplicates(t_stack_path *stack);
bool	add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map);

#endif // !PATHFINDING_BONUS_H