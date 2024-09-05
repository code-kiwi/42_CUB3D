/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 10:18:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	read_maps(t_game *game)
{
	if (game == NULL)
		return (error_print("ERR READ MAPS"), false);
	read_map(&game->maps[0], MAP0_PATH, game->anims[0]);
	read_map(&game->maps[1], MAP1_PATH, game->anims[1]);
	read_map(&game->maps[2], MAP2_PATH, game->anims[2]);
	read_map(&game->maps[3], MAP3_PATH, game->anims[3]);
	read_map(&game->maps[4], MAP4_PATH, game->anims[4]);
	return (true);
}
