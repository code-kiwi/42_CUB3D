/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/09 09:36:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BONUS_H
# define UI_BONUS_H

# include "mlx_api_bonus.h"

# define UI_PAUSE_TXT_FILE		"./assets/test_textures/transparent_pixels.xpm"
# define UI_PAUSE_W_RATIO		0.5f
# define UI_PAUSE_H_RATIO		0.5f

# define UI_PAUSE_NB_LBL		1
# define UI_PAUSE_LBL_TXT_FILE	"./assets/test_textures/pause.xpm"
# define UI_PAUSE_LBL_W_RATIO	0.3f
# define UI_PAUSE_LBL_H_RATIO	0.2f

# define UI_PAUSE_NB_BTN		2
# define UI_PAUSE_BTN1_ON_FILE	"./assets/test_textures/resume_on.xpm"
# define UI_PAUSE_BTN1_OFF_FILE	"./assets/test_textures/resume_off.xpm"
# define UI_PAUSE_BTN1_W_RATIO	0.4f
# define UI_PAUSE_BTN1_H_RATIO	0.175f
# define UI_PAUSE_BTN2_ON_FILE	"./assets/test_textures/quit_on.xpm"
# define UI_PAUSE_BTN2_OFF_FILE	"./assets/test_textures/quit_off.xpm"
# define UI_PAUSE_BTN2_W_RATIO	0.4f
# define UI_PAUSE_BTN2_H_RATIO	0.175f

typedef struct s_game		t_game;
typedef struct s_ui			t_ui;
typedef struct s_button		t_button;
typedef struct s_label		t_label;

struct s_ui
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			texture;
	size_t			nb_buttons;
	t_button		*buttons;
	size_t			nb_labels;
	t_label			*labels;
};

struct s_button
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			texture_off;
	t_image			texture_on;
	t_image			*texture_active;
	void			(*callback)(void *);
};

struct s_label
{
	t_mlx_coords	pos;
	t_mlx_coords	size;
	t_image			texture;
};

// ui functions
bool	init_all_ui(t_game *game);
void	destroy_all_ui(t_game *game);
void	destroy_ui(t_ui *ui, void *mlx_ptr);
void	draw_ui(t_ui *ui, t_image *img);
bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr);
void	disable_buttons_ui(t_ui *ui);

// label functions
bool	init_label(t_label *label, t_dimension	*dim, char *filename, \
			void *mlx_ptr);
void	destroy_label(t_label *label, void *mlx_ptr);
void	draw_labels(t_ui *ui, t_image *img);

// button functions
void	destroy_button(t_button *btn, void *mlx_ptr);
void	draw_buttons(t_ui *ui, t_image *img);
bool	is_over_button(t_button *btn, int x, int y);

#endif
