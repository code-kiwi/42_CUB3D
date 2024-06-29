/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:32:49 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 22:08:59 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_BONUS_H
# define PATHFINDING_BONUS_H

# include <stdlib.h>

# include "mlx_api_bonus.h"

# define POOL_SIZE				1000

typedef struct s_path_stack		t_stack_path;
typedef struct s_pathfinding	t_pathfinding;
typedef struct s_list			t_list;
typedef struct s_map			t_map;
typedef struct s_pool			t_pool;

struct	s_path_stack
{
	t_mlx_coords	position;
	t_stack_path	*previous_tile;
	size_t			start_distance;
	size_t			end_distance;
	size_t			total_cost;
	t_stack_path	*next;
	t_stack_path	*previous;
};

struct s_pool
{
	t_stack_path	objects[POOL_SIZE];
	int				object_remaining;
};

struct	s_pathfinding
{
	t_stack_path	*stack;
	t_mlx_coords	*start;
	t_mlx_coords	*end;
	t_stack_path	*locked_tiles;
	t_pool			pool;
};

// Path-finding functions
t_list			*find_path(t_mlx_coords *start, t_mlx_coords *end, t_map *map);
void			insert_path_node(t_stack_path **stack, t_stack_path *new_node);
t_list			*get_parcoured_path(t_pathfinding *pathfinding);
bool			add_path_node(t_mlx_coords *pos, t_pathfinding *pathfinding,
					t_stack_path *previous, size_t distance);
void			t_pathfinding_free(t_pathfinding *pathfinding);
bool			add_neighboring_tiles(t_pathfinding *pathfinding, t_map *map);
t_stack_path	*search_in_stack(t_stack_path *stack, t_mlx_coords *position);
bool			t_pathfinding_init(t_pathfinding *pathfinding, \
					t_mlx_coords *start, t_mlx_coords *end, t_map *map);

t_stack_path	*get_stack_node(t_pool *pool);

#endif
