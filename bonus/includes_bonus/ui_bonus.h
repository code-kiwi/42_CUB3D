/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/26 07:18:43 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BONUS_H
# define UI_BONUS_H

# include "mlx_api_bonus.h"

# define UI_PAUSE_TXT_FILE		"./assets/test_textures/transparent_pixels.xpm"
# define UI_PAUSE_WIDTH			1200
# define UI_PAUSE_HEIGHT		600

# define UI_PAUSE_NB_LBL		1
# define UI_PAUSE_LBL_TXT_FILE	"./assets/test_textures/pause.xpm"
# define UI_PAUSE_LBL_POS_X		500
# define UI_PAUSE_LBL_POS_Y		50
# define UI_PAUSE_LBL_WIDTH		200
# define UI_PAUSE_LBL_HEIGHT	100

# define UI_PAUSE_NB_BTN		2
# define UI_PAUSE_BTN1_ON_FILE	"./assets/test_textures/resume_on.xpm"
# define UI_PAUSE_BTN1_OFF_FILE	"./assets/test_textures/resume_off.xpm"
# define UI_PAUSE_BTN1_POS_X	400
# define UI_PAUSE_BTN1_POS_Y	200
# define UI_PAUSE_BTN1_WIDTH	400
# define UI_PAUSE_BTN1_HEIGHT	100
# define UI_PAUSE_BTN2_ON_FILE	"./assets/test_textures/quit_on.xpm"
# define UI_PAUSE_BTN2_OFF_FILE	"./assets/test_textures/quit_off.xpm"
# define UI_PAUSE_BTN2_POS_X	400
# define UI_PAUSE_BTN2_POS_Y	400
# define UI_PAUSE_BTN2_WIDTH	400
# define UI_PAUSE_BTN2_HEIGHT	100

typedef struct s_game		t_game;
typedef struct s_ui			t_ui;
typedef struct s_button		t_button;
typedef struct s_label		t_label;
typedef struct s_dimension	t_dimension;

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

struct s_dimension
{
	t_mlx_coords	coords;
	t_mlx_coords	size;
};

// ui functions
bool	init_all_ui(t_game *game);
void	destroy_all_ui(t_game *game);
void	destroy_ui(t_ui *ui, void *mlx_ptr);
void	draw_ui(t_ui *ui, t_image *img);
bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr);

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
