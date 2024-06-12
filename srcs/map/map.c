/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:43:55 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 15:07:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

#include <fcntl.h>
#include <errno.h>

bool	is_in_bounds(t_vector *position, t_map *map)
{
	if (position->x < 0
		|| position->y < 0
		|| position->x > map->length_x
		|| position->y > map->length_y)
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
		tiles = malloc((map_size_y + 1) * sizeof(char *));
		if (tiles == NULL)
			return (NULL);
		tiles[map_size_y] = NULL;
		return (tiles);
	}
	tiles = read_tiles(fd, map_size_y + 1);
	if (tiles == NULL)
		return (NULL);
	tiles[map_size_y] = line;
	return (tiles);
}

bool	read_map(t_map *map, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	map->tiles = read_tiles(fd, 0);
	if (map->tiles == NULL)
		return (false);
	map->length_y = array_length((void **)map->tiles);
	map->length_x = ft_strlen(map->tiles[0]);
	return (true);
}
