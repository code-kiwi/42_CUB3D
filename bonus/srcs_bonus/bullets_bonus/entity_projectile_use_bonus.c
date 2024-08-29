/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_projectile_use_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:59:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/29 10:35:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	entity_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;
	t_vector	*player_pos;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	if (bullet->animation != NULL)
		set_animation(sprite, bullet->animation);
	sprite->next_animation = NULL;
	player_pos = &game->player.position;
	if (get_distance(player_pos, &bullet->sprite->position) < PLAYER_RADIUS)
		player_get_damage(game, bullet->damage);
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}
