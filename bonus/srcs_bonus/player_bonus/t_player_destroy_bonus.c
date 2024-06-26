/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:07:50 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/27 18:49:35 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "player_bonus.h"
#include "mlx_api_bonus.h"
#include "animation_bonus.h"

void	destroy_player(t_player *player, void *mlx_ptr)
{
	if (player == NULL || mlx_ptr == NULL)
		return ;
	if (player->display.frames != NULL)
	{
		destroy_animation(player->display.frames, mlx_ptr, true);
		player->display.frames = NULL;
	}
	if (player->display.taget_texture.ptr != NULL)
		t_image_destroy(mlx_ptr, &player->display.taget_texture, false);
}
