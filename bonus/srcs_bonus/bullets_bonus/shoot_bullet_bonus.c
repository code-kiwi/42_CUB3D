/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bullet_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:25 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 15:22:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "bullets_bonus.h"
#include "libft.h"

bool	shoot_bullet(t_game *game, t_vector *position, t_vector *direction,
	void (*use)(t_game *))
{
	t_bullet	*new_bullet;
	t_list		*new_node;

	new_bullet = ft_calloc(1, sizeof(t_bullet));
	if (new_bullet == NULL)
		return (false);
	new_node = ft_lstnew(new_bullet);
	if (new_node == NULL)
		return (free(new_bullet), false);
	ft_lstadd_front(&game->bullets, new_node);
	new_bullet->position = *position;
	new_bullet->move = *direction;
	new_bullet->use = use;
	return (true);
}