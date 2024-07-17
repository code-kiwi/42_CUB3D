/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bullet_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:17:13 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 10:58:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullets_bonus.h"
#include "entities_bonus.h"
#include "cub3d_bonus.h"

static void	update_bullet(t_game *game, t_bullet *bullet, float delta_time)
{
	t_vector	realtime_move;

	if (game == NULL || bullet == NULL || bullet->sprite == NULL)
		return ;
	realtime_move.x = bullet->move.x * delta_time;
	realtime_move.y = bullet->move.y * delta_time;
	if (!move_entity(game->entities, &bullet->sprite->position, &realtime_move,
			&game->map) && bullet->use != NULL)
	{
		bullet->use(game);
	}
}

void	update_bullets(t_game *game, float delta_time)
{
	t_list		*current;
	t_bullet	*bullet;

	if (game == NULL || game->bullets == NULL)
		return ;
	current = game->bullets;
	while (current)
	{
		bullet = current->content;
		update_bullet(game, bullet, delta_time);
		current = current->next;
	}
}
