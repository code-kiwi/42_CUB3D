/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:04 by brappo            #+#    #+#             */
/*   Updated: 2024/06/20 16:26:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	**max(void **array, size_t length, int compare (void **, void **))
{
	void	**max;
	size_t	index;

	if (array == NULL)
		return (NULL);
	index = 0;
	max = array;
	while (index < length)
	{
		if (compare(array + index, max) > 0)
			max = array + index;
		index++;
	}
	return (max);
}

static void	swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(void **array, size_t length, int compare(void **, void **))
{
	size_t	index;
	void	**max_element;

	index = 0;
	while (length > 0)
	{
		max_element = max(array + index, length, compare);
		swap(array + index, max_element);
		length--;
		index++;
	}
}