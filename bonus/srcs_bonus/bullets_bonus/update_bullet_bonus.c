/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bullet_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:17:13 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 10:19:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullets_bonus.h"
#include "entities_bonus.h"
#include "cub3d_bonus.h"

void	update_bullet(t_game *game, t_bullet *bullet)
{
	if (!move_entity(game->entities, &bullet->sprite->position, &bullet->move,
			&game->map))
	{
		bullet->use(game);
	}
}
