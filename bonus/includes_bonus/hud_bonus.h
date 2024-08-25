/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:33 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/25 18:51:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_BONUS_H
# define HUD_BONUS_H

# include "mlx_api_bonus.h"

# define HUD_W_RATIO		0.2f
# define HUD_H_RATIO		0.1f

typedef struct s_hud	t_hud;
typedef struct s_game	t_game;

struct s_hud
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture_bg;
	t_image			*texture_lbl_health;
	t_image			*texture_lbl_weapon;
	t_image			*texture_dig_0;
	t_image			*texture_dig_1;
	t_image			*texture_dig_2;
	t_image			*texture_dig_3;
	t_image			*texture_dig_4;
	t_image			*texture_dig_5;
	t_image			*texture_dig_6;
	t_image			*texture_dig_7;
	t_image			*texture_dig_8;
	t_image			*texture_dig_9;
};

// HUD functions
bool	init_hud(t_game *game);
void	draw_hud(t_game *game);

#endif
