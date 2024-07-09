/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:29:56 by brappo            #+#    #+#             */
/*   Updated: 2024/07/09 10:17:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "map_bonus.h"
#include "libft.h"

static bool	parse_element(t_map *map, char *element, char **identifier)
{
	char	**infos;
	ssize_t	identifier_index;

	infos = ft_split(element, " ");
	if (array_length((void **)infos) != 2)
	{
		ft_free_str_array(&infos);
		return (error_print(ERR_MISSING_COMPONENT), false);
	}
	identifier_index = find_str_in_array(identifier, infos[0], MAP_NB_IDS);
	if (identifier_index == -1)
	{
		ft_free_str_array(&infos);
		return (error_print(ERR_IDENTIFIER), false);
	}
	map->textures[identifier_index] = infos[1];
	infos[1] = NULL;
	identifier[identifier_index] = "";
	free_array(infos, 2, true);
	return (true);
}

static void	init_identifier(char **identifier)
{
	identifier[0] = ID_TEXTURE_NORTH;
	identifier[1] = ID_TEXTURE_SOUTH;
	identifier[2] = ID_TEXTURE_WEST;
	identifier[3] = ID_TEXTURE_EAST;
	identifier[4] = ID_TEXTURE_FLOOR;
	identifier[5] = ID_TEXTURE_CEILING;
	identifier[6] = ID_TEXTURE_DOOR;
	identifier[7] = ID_TEXTURE_ENTITY;
}

bool	read_elements(t_map *map, int fd)
{
	char			*line;
	unsigned int	elements_read;
	char			*identifier[MAP_NB_IDS];

	elements_read = 0;
	init_identifier(identifier);
	ft_bzero(map->textures, MAP_NB_IDS * sizeof(char *));
	while (elements_read < MAP_NB_IDS)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error_print(ERR_MAP_CONTENT), false);
		remove_last_breakline(line);
		if (line[0] != '\0')
		{
			if (!parse_element(map, line, identifier))
			{
				free(line);
				return (false);
			}
			elements_read++;
		}
		free(line);
	}
	return (true);
}
