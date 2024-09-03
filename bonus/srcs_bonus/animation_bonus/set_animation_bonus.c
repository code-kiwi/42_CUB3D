/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:54:21 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 13:41:20 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
