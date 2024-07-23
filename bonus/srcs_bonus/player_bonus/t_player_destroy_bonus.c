/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:07:50 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/23 10:19:51 by brappo           ###   ########.fr       */
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
		destroy_animation_textures(player->display.frames, mlx_ptr);
		player->display.frames = NULL;
	}
	if (player->display.target_texture.ptr != NULL)
		t_image_destroy(mlx_ptr, &player->display.target_texture, false);
}
