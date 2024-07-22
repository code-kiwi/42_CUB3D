/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 16:08:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"
#include "mlx_api_bonus.h"

void    use_weapon(t_weapon *weapon, t_game *game)
{
    if (weapon == NULL || game == NULL)
        return ;
    weapon->curr_frame_link = weapon->frames_action;
    weapon->curr_frame = (t_image *) weapon->curr_frame_link->content;
    set_weapon_positions(weapon, game);
}