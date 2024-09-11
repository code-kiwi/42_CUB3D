/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/11 04:49:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

bool	read_maps(t_game *game)
{
	size_t		i;
	static char	*filenames[NB_MAPS] = {
		MAP0_PATH, MAP1_PATH, MAP2_PATH, MAP3_PATH, MAP4_PATH
	};

	if (game == NULL)
		return (error_print("ERR READ MAPS"), false);
	i = 0;
	while (i < NB_MAPS)
	{
		if (!read_map(&game->maps[i], filenames[i], game->anims[i]))
			return (false);
		if (!init_doors(&game->maps[i]))
			return (false);
		i++;
	}
	return (true);
}
