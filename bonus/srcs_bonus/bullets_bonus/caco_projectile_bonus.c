/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_projectile_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/07/22 10:57:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	caco_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	sprite->animation = game->textures[IDX_TXTR_CACO_PROJ_DEATH];
	sprite->next_animation = NULL;
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}

void	caco_projectile_init(t_list *textures[MAP_NB_IDS], t_bullet *bullet)
{
	t_sprite_init(bullet->sprite, textures[IDX_TXTR_IMP_PROJ_LIVE], WIN_HEIGHT);
	bullet->use = caco_projectile_use;
}
