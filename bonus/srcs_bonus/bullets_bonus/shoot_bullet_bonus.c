/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bullet_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:06:25 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 11:14:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "bullets_bonus.h"
#include "entities_bonus.h"
#include "libft.h"

bool	shoot_bullet(t_game *game, t_vector *position, t_vector *direction,
	void (*init_bullet)(t_animation anim[MAP_NB_IDS], t_bullet *))
{
	t_bullet	*new_bullet;
	t_list		*new_node;
	t_sprite	*new_sprite;

	if (game == NULL || position == NULL || direction == NULL)
		return (false);
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
	init_bullet(game->anim, new_bullet);
	new_sprite->distance = get_distance(position, &game->player.position);
	return (true);
}
