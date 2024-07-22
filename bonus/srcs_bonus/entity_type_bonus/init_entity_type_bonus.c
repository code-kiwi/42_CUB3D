/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_type_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:26:19 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 10:26:12 by brappo           ###   ########.fr       */
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
	else
		return (false);
}
