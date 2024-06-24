/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:32:49 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 22:42:27 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_BONUS_H
# define PATHFINDING_BONUS_H

# include "mlx_api.h"
# include <stdlib.h>

typedef struct s_path_stack	t_stack_path;

struct	s_path_stack
{
	t_mlx_coords	position;
	size_t			start_distance;
	size_t			end_distance;
	size_t			total_cost;
	t_stack_path	*next;
};

#endif // !PATHFINDING_BONUS_H