/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:26:47 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

void	use_weapon(t_weapon *weapon, t_game *game)
{
	if (
		game == NULL || weapon == NULL
		|| (weapon->is_limited && weapon->remaining_use == 0)
	)
		return ;
	weapon->curr_frame_link = weapon->frames_action;
	weapon->curr_frame = (t_image *) weapon->curr_frame_link->content;
	set_weapon_position(weapon, &game->mlx);
	if (weapon->action != NULL)
		weapon->action(weapon, game);
	if (weapon->is_use_continuous && !weapon->using)
		weapon->using = true;
}

void	stop_weapon(t_weapon *weapon)
{
	if (weapon == NULL || !weapon->is_use_continuous || !weapon->using)
		return ;
	weapon->using = false;
}
