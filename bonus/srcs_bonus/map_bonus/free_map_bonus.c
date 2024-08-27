/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:39:48 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 14:07:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "get_next_line.h"

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	free_array(map->textures, MAP_NB_IDS, false);
	free_array(map->tiles, map->lines_count, true);
	map->tiles = NULL;
	free(map->lines_lengths);
	map->lines_lengths = NULL;
	get_next_line(-1);
}
