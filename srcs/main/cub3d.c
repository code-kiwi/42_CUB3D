/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:03:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 15:58:27 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map		map;
	float		length;
	t_vector	intersection;
	t_vector	position;
	t_vector	slope;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (!read_map(&map, argv[1]))
		return (EXIT_FAILURE);
	print_str_array(map.tiles);
	vector_init(&position, 1, 1);
	get_slope(&slope, 6 * PI / 4);
	vector_print("position : ", &position);
	vector_print("slope : ", &slope);
	length = raycast(position, &slope, &map);
	printf("length : %f\n", length);
	vector_init(&intersection, position.x + slope.x * length,
		position.y - slope.y * length);
	vector_print("intersection : ", &intersection);
	free_array(map.tiles);
	free(map.lines_lengths);
	return (EXIT_SUCCESS);
}
