/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 11:09:48 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

static void	init_w1_hand(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = (t_image *) game->textures[IDX_TXTR_W1_HAND]->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->textures[IDX_TXTR_W1_PUNCH];
	weapon->frames_reload = NULL;
	weapon->frames_bullet = NULL;
	weapon->target = NULL;
	weapon->num_loads = 0;
	weapon->load_capacity = 0;
	weapon->remaining_use = 0;
	weapon->is_limited = false;
	weapon->is_use_continuous = false;
	weapon->id = 'M';
	set_weapon_positions(weapon, game);
}

static void	init_w2_pistol(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = (t_image *) game->textures[IDX_TXTR_W2_PISTOL]->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->textures[IDX_TXTR_W2_PISTOL]->next;
	weapon->frames_reload = NULL;
	weapon->frames_bullet = NULL;
	weapon->target = (t_image *) game->textures[IDX_TXTR_TARGET1]->content;
	weapon->num_loads = 2;
	weapon->load_capacity = 5;
	weapon->remaining_use = 5;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->id = 'N';
	set_weapon_positions(weapon, game);
}

#include <stdio.h>
static bool	resize_weapon_img(t_image *img, int height, void *mlx_ptr)
{
	float			ratio;
	t_mlx_coords	size;

	ratio = (float) height / (float) img->height;
	size.x = ratio * img->width;
	size.y = ratio * img->height;
	return (t_image_resize(mlx_ptr, img, &size));
}

static bool	resize_weapon_imgs(t_weapon *weapon, t_mlx *mlx)
{
	int		t_height;
	t_list	*current;

	t_height = WEAPONS_H_RATIO * mlx->height;
	printf("TARGET HEIGHT: %d\n", t_height);
	if (
		weapon->frame_default != NULL
		&& !resize_weapon_img(weapon->frame_default, t_height, mlx->mlx_ptr)
	)
		return (false);
	current = weapon->frames_action;
	while (current != NULL)
	{
		if (!resize_weapon_img((t_image *)current->content, t_height, mlx->mlx_ptr))
			return (false);
		current = current->next;
	}
	current = weapon->frames_reload;
	while (current != NULL)
	{
		if (!resize_weapon_img((t_image *)current->content, t_height, mlx->mlx_ptr))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	init_resize_imgs(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < NB_TOT_WEAPONS)
	{
		if (!resize_weapon_imgs(&weapons[i], mlx))
			return (false);
		i++;
	}
	return (true);
}

bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	init_w1_hand(&game->weapons[IDX_W1_HAND], game);
	init_w2_pistol(&game->weapons[IDX_W2_PISTOL], game);
	if (!init_resize_imgs(game->weapons, &game->mlx))
		return (error_print(ERR_WEAPONS_RESIZE), false);
	set_weapon_positions(&game->weapons[0], game);
	set_weapon_positions(&game->weapons[1], game);
	return (true);
}
