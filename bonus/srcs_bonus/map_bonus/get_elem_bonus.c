/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:06 by root              #+#    #+#             */
/*   Updated: 2024/06/29 12:57:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

bool	get_elemn_into_list(t_map *map, t_list **dest, char id,
	bool add_elem(t_list **, float, float))
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == id)
			{
				if (!add_elem(dest, x + 0.5, y + 0.5))
				{
					ft_lstclear(dest, free);
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}
