/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:53:41 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/16 17:46:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>

#include "cub3d.h"
#include "map.h"
#include "libft.h"

static char	**read_tiles(int fd, size_t map_size_y)
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
	if (line[0] == '\n')
	{
		free(line);
		return (read_tiles(fd, map_size_y));
	}
	tiles = read_tiles(fd, map_size_y + 1);
	if (tiles == NULL)
	{
		free(line);
		return (NULL);
	}
	tiles[map_size_y] = line;
	return (tiles);
}

static bool	get_lines_lengths(t_map *map)
{
	size_t	index;

	index = 0;
	map->lines_count = array_length((void **)map->tiles);
	if (map->lines_count == 0)
		return (false);
	map->lines_lengths = ft_calloc(map->lines_count, sizeof(size_t));
	if (map->lines_lengths == NULL)
		return (false);
	while (map->tiles[index])
	{
		map->lines_lengths[index] = ft_strlen(map->tiles[index]);
		index++;
	}
	return (true);
}

void	free_map(t_map *map)
{
	free_array(map->textures, MAP_NB_IDS, false);
	free_array(map->tiles, map->lines_count, true);
	free(map->lines_lengths);
	get_next_line(-1);
}

bool	read_map(t_map *map, char *filename)
{
	int		fd;

	ft_bzero(map, sizeof(t_map));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	if (!read_elements(map, fd))
	{
		free_map(map);
		close(fd);
		return (false);
	}
	map->tiles = read_tiles(fd, 0);
	close(fd);
	if (map->tiles == NULL
		|| !get_lines_lengths(map)
		|| !is_map_valid(map))
	{
		free_map(map);
		return (false);
	}
	return (true);
}
