/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:43:38 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 17:21:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

void	t_vector_init(t_vector *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}

float	get_squared_distance(t_vector *a, t_vector *b)
{
	return ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}
