/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_damage_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:10:51 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 14:12:20 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_get_damage(t_game *game, size_t damage)
{
	t_player	*player;

	player = &game->player;
	if (player->health_point > damage)
		player->health_point -= damage;
	else
		t_game_destroy_and_exit(game);
}