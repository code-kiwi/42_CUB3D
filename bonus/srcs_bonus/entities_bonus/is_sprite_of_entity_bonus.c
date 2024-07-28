/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite_of_entity_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:04:52 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/28 10:05:34 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"

int	is_sprite_of_entity(void *entity_void, void *sprite_void)
{
	t_entity	*entity;
	t_sprite	*sprite;

	entity = entity_void;
	sprite = sprite_void;
	return (!(entity->sprite == sprite));
}