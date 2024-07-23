/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_type_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:26:19 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 21:15:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "map_bonus.h"

bool	init_entity_type(t_entity *entity, char id, \
	t_animation anim[MAP_NB_IDS])
{
	char		*id_pos;
	static char	*ids = IDS_MAP_ENTITY;
	static bool	(*inits[12])(t_entity *, t_animation[MAP_NB_IDS]) = {
		demon_init, imp_init, caco_init, boh_init, lost_soul_init, \
	pain_elem_init, cyber_init, revenant_init, mancubus_init, arch_vile_init, \
	sergeant_init, commando_init};

	id_pos = ft_strchr(ids, id);
	if (id_pos == NULL || id_pos - ids >= 12)
		return (false);
	return (inits[id_pos - ids](entity, anim));
}
