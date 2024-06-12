/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 11:45:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_map
{
	char	**tiles;
	size_t	length_x;
	size_t	length_y;
}	t_map;

bool		is_in_bounds(t_vector *position, t_map *map);
void		copy(t_vector *dest, t_vector *src);
t_vector	vector_error();
int			sign(float value);

#endif
