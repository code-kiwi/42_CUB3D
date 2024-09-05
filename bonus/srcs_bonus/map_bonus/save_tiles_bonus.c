/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:59:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 14:37:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

bool	save_map_tiles(t_map *map)
{
	char	**save;
	size_t	i;

	if (map == NULL || map->tiles == NULL)
		return (false);
	save = (char **) ft_calloc(map->lines_count + 1, sizeof(char *));
	if (save == NULL)
		return (false);
	i = 0;
	while (i < map->lines_count)
	{
		save[i] = ft_strdup(map->tiles[i]);
		if (save[i] == NULL)
		{
			ft_free_str_array(&save);
			return (false);
		}
		i++;
	}
	map->tiles_save = save;
	return (true);
}