/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 00:54:07 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_ui_textures(void *mlx_ptr, t_image textures[UI_NB_TEXTURES])
{
	size_t	i;

	if (textures == NULL)
		return ;
	i = 0;
	while (i < UI_NB_TEXTURES)
	{
		if (textures[i].ptr != NULL)
			t_image_destroy(mlx_ptr, &textures[i], false);
		i++;
	}
}

void	destroy_game_uis(t_game *game, t_game_uis *uis)
{
	if (game == NULL || uis == NULL)
		return ;
	free_ui_textures(game->mlx.mlx_ptr, uis->textures);
}
