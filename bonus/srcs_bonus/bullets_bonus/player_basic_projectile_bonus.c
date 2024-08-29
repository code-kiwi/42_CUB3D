/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_basic_projectile_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:50:01 by brappo            #+#    #+#             */
/*   Updated: 2024/08/29 15:31:17 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	player_gun_proj_init(
	t_bullet *bullet,
	t_weapon *weapon
)
{
	t_sprite_init(bullet->sprite, weapon->bullet_live_anim, WIN_HEIGHT);
	bullet->use = weapon->bullet_use;
	bullet->speed = weapon->bullet_speed;
	bullet->damage = weapon->damage;
	bullet->animation = weapon->bullet_death_anim;
}
