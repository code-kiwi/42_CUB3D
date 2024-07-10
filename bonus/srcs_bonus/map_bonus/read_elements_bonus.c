/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:29:56 by brappo            #+#    #+#             */
/*   Updated: 2024/07/10 14:25:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "map_bonus.h"
#include "libft.h"

static bool	get_texture_size(t_mlx_coords *out, char *size)
{
	char	**values;

	if (out == NULL || size == NULL)
		return (false);
	values = ft_split(size, ",");
	if (array_length((void **)values) != 2
		|| !is_number(values[0]) || !is_number(values[1]))
	{
		ft_free_str_array(&values);
		return (error_print(ERR_BAD_SIZE), false);
	}
	if (ft_strlen(values[0]) >= 5 || ft_strlen(values[1]) >= 5)
	{
		ft_free_str_array(&values);
		return (error_print(ERR_SIZE_TOO_BIG), false);
	}
	out->x = ft_atoi(values[0]);
	out->y = ft_atoi(values[1]);
	ft_free_str_array(&values);
	if (out->x <= 0 || out->y <= 0)
		return (error_print(ERR_NEGATIVE_SIZE), false);
	return (true);
}

static bool	parse_element(t_map *map, char *element, char **identifier)
{
	char	**infos;
	ssize_t	identifier_index;

	if (map == NULL || element == NULL || identifier == NULL)
		return (false);
	infos = ft_split(element, " ");
	if (array_length((void **)infos) != 3)
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
	if (!get_texture_size(&map->texture_size[identifier_index], infos[2]))
		return (ft_free_str_array(&infos), false);
	free(infos[2]);
	map->textures[identifier_index] = infos[1];
	identifier[identifier_index] = "";
	free_array(infos, 1, true);
	return (true);
}

static void	init_identifier(char **identifier)
{
	if (identifier == NULL)
		return ;
	identifier[0] = ID_TEXTURE_NORTH;
	identifier[1] = ID_TEXTURE_SOUTH;
	identifier[2] = ID_TEXTURE_WEST;
	identifier[3] = ID_TEXTURE_EAST;
	identifier[4] = ID_TEXTURE_FLOOR;
	identifier[5] = ID_TEXTURE_CEILING;
	identifier[6] = ID_TEXTURE_DOOR;
	identifier[7] = ID_TEXTURE_ENTITY;
	identifier[8] = ID_TEXTURE_UI_PAUSE_BG;
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
