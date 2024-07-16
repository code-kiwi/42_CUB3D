/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:16:00 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 13:24:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "animation_bonus.h"
#include "libft.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"

void	update_animations(t_game *game, float delta_time)
{
	t_list		*current;
	t_sprite	*sprite;

	game->frame_update_delta += delta_time;
	if (game->frame_update_delta < ANIMATION_UPDATE)
		return ;
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		sprite->animation = sprite->animation->next;
		if (sprite->animation == NULL)
			sprite->animation = sprite->next_animation;
		current = current->next;
		if (sprite->animation == NULL)
			ft_lst_remove_if(&game->sprites, sprite, equal, free);
	}
	game->frame_update_delta = 0;
}
