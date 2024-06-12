/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:42:24 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 15:11:41 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

#include "cub3d.h"

#include <stdio.h>

void	copy(t_vector *dest, t_vector *src)
{
	dest->x = src->x;
	dest->y = src->y;
}

t_vector	vector_error(void)
{
	t_vector	error;

	error.x = -1;
	error.y = -1;
	return (error);
}

void	vector_print(char *prefix, t_vector *vector)
{
	if (prefix != NULL)
		printf("%s", prefix);
	printf("x : %f, y : %f\n", vector->x, vector->y);
	fflush(stdout);
}

void	vector_init(t_vector *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}

void	get_slope(t_vector *slope, float angle_rad)
{
	slope->x = cos(angle_rad);
	slope->y = sin(angle_rad);
}
