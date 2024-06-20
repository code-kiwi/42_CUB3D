/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:42:24 by brappo            #+#    #+#             */
/*   Updated: 2024/06/20 12:50:17 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d_bonus.h"

void	t_vector_copy(t_vector *dest, t_vector *src)
{
	dest->x = src->x;
	dest->y = src->y;
}

void	t_vector_print(char *prefix, t_vector *vector)
{
	if (prefix != NULL)
		printf("%s", prefix);
	printf("x : %f, y : %f\n", vector->x, vector->y);
	fflush(stdout);
}

void	t_vector_init(t_vector *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}

void	t_vector_get_slope(t_vector *slope, float angle_rad)
{
	slope->x = cos(angle_rad);
	slope->y = sin(angle_rad);
}

float	get_distance(t_vector *a, t_vector *b)
{
	return (sqrtf(powf(a->x - b->x, 2) + powf(a->y - b->y, 2)));
}
