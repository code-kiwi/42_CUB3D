/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:04 by brappo            #+#    #+#             */
/*   Updated: 2024/06/20 13:01:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static float	*maxf(float *array, size_t length)
{
	float	*max;
	size_t	index;

	if (array == NULL)
		return (NULL);
	index = 0;
	max = array;
	while (index < length)
	{
		if (array[index] > *max)
			max = array + index;
		index++;
	}
	return (max);
}

static void	swapf(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sortf(float *array, size_t length)
{
	size_t	index;
	float	*max;

	index = 0;
	while (length > 0)
	{
		max = maxf(array, length);
		swapf(array + index, max);
		length--;
		index++;
	}
}