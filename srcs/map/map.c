/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:43:55 by brappo            #+#    #+#             */
/*   Updated: 2024/06/13 09:56:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <errno.h>
#include <math.h>

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->x > map->lines_lengths[(int)floorf(position->y)]
		|| position->y > map->lines_count)
		return (false);
	return (true);
}

char	**read_tiles(int fd, size_t map_size_y)
{
	char	*line;
	char	**tiles;

	line = get_next_line(fd);
	if (line == NULL)
	{
		if (errno != 0)
			return (NULL);
		tiles = ft_calloc(map_size_y + 1, sizeof(char *));
		return (tiles);
	}
	tiles = read_tiles(fd, map_size_y + 1);
	if (tiles == NULL)
		return (NULL);
	tiles[map_size_y] = line;
	return (tiles);
}

bool	get_lines_lengths(t_map *map)
{
	size_t	index;

	index = 0;
	map->lines_count = array_length((void **)map->tiles);
	map->lines_lengths = ft_calloc(map->lines_count, sizeof(char *));
	if (map->lines_lengths == NULL)
	{
		free_array(map->tiles);
		return (false);
	}
	while (map->tiles[index])
	{
		map->lines_lengths[index] = ft_strlen(map->tiles[index]);
		index++;
	}
	return (true);
}

bool	read_map(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	map->tiles = read_tiles(fd, 0);
	if (map->tiles == NULL
		|| !get_lines_lengths(map))
	{
		close(fd);
		return (false);
	}
	return (true);
}
