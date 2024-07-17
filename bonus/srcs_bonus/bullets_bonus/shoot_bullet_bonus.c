/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bullet_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:25 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 10:30:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "bullets_bonus.h"
#include "entities_bonus.h"
#include "libft.h"

bool	shoot_bullet(t_game *game, t_vector *position, t_vector *direction,
	void (*use)(t_game *))
{
	t_bullet	*new_bullet;
	t_list		*new_node;
	t_sprite	*new_sprite;

	new_sprite = add_sprite(game, position->x, position->y, 'c');
	if (new_sprite == NULL)
		return (false);
	new_bullet = ft_calloc(1, sizeof(t_bullet));
	if (new_bullet == NULL)
		return (false);
	new_bullet->sprite = new_sprite;
	new_node = ft_lstnew(new_bullet);
	if (new_node == NULL)
		return (free(new_bullet), false);
	ft_lstadd_front(&game->bullets, new_node);
	new_bullet->move = *direction;
	new_bullet->use = use;
	return (true);
}
