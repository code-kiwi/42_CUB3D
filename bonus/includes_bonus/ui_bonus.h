/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 10:59:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BONUS_H
# define UI_BONUS_H

# include "mlx_api_bonus.h"
# include "map_bonus.h"

# define UI_PAUSE_W_RATIO			0.5f
# define UI_PAUSE_H_RATIO			0.5f
# define UI_PAUSE_NB_LBL			1
# define UI_PAUSE_LBL_W_RATIO		0.3f
# define UI_PAUSE_LBL_H_RATIO		0.2f
# define UI_PAUSE_NB_BTN			2
# define UI_PAUSE_BTN1_W_RATIO		0.4f
# define UI_PAUSE_BTN1_H_RATIO		0.175f
# define UI_PAUSE_BTN2_W_RATIO		0.4f
# define UI_PAUSE_BTN2_H_RATIO		0.175f

# define UI_GAMEOVER_W_RATIO		0.5f
# define UI_GAMEOVER_H_RATIO		0.5f
# define UI_GAMEOVER_NB_LBL			1
# define UI_GAMEOVER_LBL_W_RATIO	0.75f
# define UI_GAMEOVER_LBL_H_RATIO	0.3f
# define UI_GAMEOVER_NB_BTN			1
# define UI_GAMEOVER_BTN_W_RATIO	0.4f
# define UI_GAMEOVER_BTN_H_RATIO	0.175f

# define UI_WIN_W_RATIO				0.5f
# define UI_WIN_H_RATIO				0.75f
# define UI_WIN_NB_LBL				2
# define UI_WIN_LBL_W_RATIO			0.75f
# define UI_WIN_LBL_H_RATIO			0.25f
# define UI_WIN_LBL_TROPHY_W_RATIO	0.25f
# define UI_WIN_LBL_TROPHY_H_RATIO	0.3f
# define UI_WIN_NB_BTN				1
# define UI_WIN_BTN_W_RATIO			0.4f
# define UI_WIN_BTN_H_RATIO			0.125f

# define UI_HOME_W_RATIO			1.0f
# define UI_HOME_H_RATIO			1.0f
# define UI_HOME_NB_LBL				1
# define UI_HOME_LBL_W_RATIO		0.39f
# define UI_HOME_LBL_H_RATIO		0.31f
# define UI_HOME_NB_BTN				2
# define UI_HOME_BTN_W_RATIO		0.21f	
# define UI_HOME_BTN_H_RATIO		0.0925f

typedef struct s_game		t_game;
typedef struct s_ui			t_ui;
typedef struct s_button		t_button;
typedef struct s_label		t_label;
typedef struct s_list		t_list;

struct s_ui
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture;
	size_t			nb_buttons;
	t_button		*buttons;
	size_t			nb_labels;
	t_label			*labels;
};

struct s_button
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture_off;
	t_image			*texture_on;
	t_image			*texture_active;
	void			(*callback)(void *);
};

struct s_label
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			*texture;
};

// ui functions
bool	init_all_ui(t_game *game);
void	destroy_all_ui(t_game *game);
void	destroy_ui(t_ui *ui, void *mlx_ptr);
void	draw_ui(t_ui *ui, t_image *img);
bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr, \
			t_animation anim[MAP_NB_IDS]);
bool	init_ui_gameover(t_ui *ui_gameover, void *mlx_ptr, \
			t_animation anim[MAP_NB_IDS]);
bool	init_ui_win(t_ui *ui_win, void *mlx_ptr, t_animation anim[MAP_NB_IDS]);
bool	init_ui_home(t_ui *ui_home, void *mlx_ptr, \
			t_animation anim[MAP_NB_IDS]);
void	disable_buttons_ui(t_ui *ui);

// label functions
bool	init_label(t_label *label, t_dimension	*dim, t_image *texture, \
			void *mlx_ptr);
void	draw_labels(t_ui *ui, t_image *img);

// button functions
void	draw_buttons(t_ui *ui, t_image *img);
bool	is_over_button(t_button *btn, int x, int y);

#endif
