/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 11:49:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BONUS_H
# define UI_BONUS_H

# include "mlx_api_bonus.h"

# define UI_PAUSE_TXT_FILE	"./assets/test_textures/sand.xpm"
# define UI_PAUSE_POS_X		100
# define UI_PAUSE_POS_Y		100
# define UI_PAUSE_WIDTH		200
# define UI_PAUSE_HEIGHT	100

typedef struct s_ui		t_ui;
typedef struct s_button	t_button;

struct s_ui
{
	t_mlx_coords	pos;
	int				width;
	int				height;
	t_image			texture;
	t_button		*buttons;
};

struct s_button
{
	t_mlx_coords	pos;
	int				width;
	int				height;
	t_image			texture;
	void			(*callback)(void *);
};

// ui functions
bool	init_all_ui(t_game *game);
void	destroy_all_ui(t_game *game);

#endif
