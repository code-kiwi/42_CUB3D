/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_anim_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:16:00 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 10:24:24 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "animation_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"

static void	update_sprite_anim(t_sprite *sprite, t_game *game)
{
	sprite->frame_update_delta = 0;
	sprite->texture = sprite->texture->next;
	if (sprite->texture == NULL)
	{
		if (sprite->animation->on_end != NULL)
			sprite->animation->on_end(game, sprite);
		sprite->animation = sprite->next_animation;
		if (sprite->animation == NULL)
			ft_lst_remove_if(&game->sprites, sprite, equal, free);
		else
			sprite->texture = sprite->animation->textures;
	}
}

void	update_animations(t_game *game, float delta_time)
{
	t_list		*current;
	t_sprite	*sprite;

	if (game == NULL || game->sprites == NULL)
		return ;
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		current = current->next;
		sprite->frame_update_delta += delta_time;
		if (sprite->animation
			&& sprite->frame_update_delta >= sprite->animation->wait
			&& sprite->animate)
		{
			update_sprite_anim(sprite, game);
		}
	}
}
