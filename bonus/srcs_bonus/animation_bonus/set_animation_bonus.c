/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:54:21 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 14:59:13 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation_bonus.h"
#include "sprite_bonus.h"

void	set_animation(t_sprite *sprite, t_animation *animation)
{
	if (sprite == NULL)
		return ;
	sprite->animation = animation;
	if (animation != NULL)
		sprite->texture = animation->textures;
	sprite->frame_update_delta = 0;
	sprite->animate = true;
}
