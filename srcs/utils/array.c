/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:57 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 14:58:09 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

size_t	array_length(void **array)
{
	size_t	index;

	if (array == NULL)
		return (0);
	index = 0;
	while (array[index] != NULL)
		index++;
	return (index);
}
void	print_str_array(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		printf("%s\n", array[index]);
		index++;
	}
}

void	free_array(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
