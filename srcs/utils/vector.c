/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:42:24 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 11:43:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"

void	copy(t_vector *dest, t_vector *src)
{
	dest->x = src->x;
	dest->y = src->y;
}

t_vector	vector_error()
{
	t_vector	error;

	error.x = -1;
	error.y = -1;
	return (error);
}