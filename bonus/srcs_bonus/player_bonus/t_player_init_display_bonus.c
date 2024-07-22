/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init_display_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:32:59 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/22 10:30:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "animation_bonus.h"
#include "mlx_api_bonus.h"
#include "player_bonus.h"
#include "libft.h"

bool	init_display_target(t_player_display *display, void *mlx_ptr)
{
	if (!t_image_import_file(&display->target_texture, \
			PLAYER_TARGET_TEXTURE_FILE, mlx_ptr, NULL))
		return (false);
	display->target_coords.x = (WIN_WIDTH - display->target_texture.width) / 2;
	display->target_coords.y = \
		(WIN_HEIGHT - display->target_texture.height) / 2;
	display->target_size.x = display->target_texture.width;
	display->target_size.y = display->target_texture.height;
	return (true);
}

bool	init_display_frames(t_player_display *display, void *mlx_ptr)
{
	t_image	texture;

	if (!t_image_import_file(&texture, PLAYER_TEXTURE_FILE, mlx_ptr, NULL))
		return (false);
	display->size.x = PLAYER_TEXTURE_WIDTH;
	display->size.y = PLAYER_TEXTURE_HEIGHT;
	display->frames = create_animation(&texture, &display->size, mlx_ptr,
		PLAYER_TEXTURE_FILE);
	t_image_destroy(mlx_ptr, &texture, false);
	if (display->frames == NULL)
		return (false);
	display->frame_curr = display->frames;
	display->coords.x = (WIN_WIDTH - display->size.x) / 2 \
		+ PLAYER_TEXTURE_X_OFFSET;
	display->coords.y = WIN_HEIGHT - display->size.y;
	return (true);
}

bool	t_player_init_display(t_player_display *display, void *mlx_ptr)
{
	if (
		display == NULL || mlx_ptr == NULL
		|| !init_display_frames(display, mlx_ptr)
	)
		return (false);
	if (!init_display_target(display, mlx_ptr))
	{
		destroy_animation(display->frames, mlx_ptr, true);
		display->frames = NULL;
		return (false);
	}
	return (true);
}
