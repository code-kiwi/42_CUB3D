/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entity_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:19:58 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 09:35:07 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"

void	t_entity_destroy(void *data)
{
	t_entity	*entity;

	entity = data;
	ft_lstclear(&entity->path, free);
	if (entity->type != NULL)
		free(entity->type);
	free(entity);
}
