/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_type_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:26:19 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 14:48:10 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "map_bonus.h"

bool	init_entity_type(t_entity *entity, char id, \
	t_list *textures[MAP_NB_IDS])
{
	if (id == ID_MAP_DEMON)
		return (demon_init(entity, textures));
	else if (id == ID_MAP_IMP)
		return (imp_init(entity, textures));
	else if (id == ID_MAP_CACO)
		return (caco_init(entity, textures));
	else if (id == ID_MAP_BOH)
		return (boh_init(entity, textures));
	else if (id == ID_MAP_LOST_SOUL)
		return (lost_soul_init(entity, textures));
	else if (id == ID_MAP_PAIN_ELEM)
		return (pain_elem_init(entity, textures));
	else if (id == ID_MAP_CYBER)
		return (cyber_init(entity, textures));
	else
		return (false);
}
