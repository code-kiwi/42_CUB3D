/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 15:22:26 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

# include "mlx_api_bonus.h"
# include "animation_bonus.h"

# define ID_MAP_WALL					'1'
# define ID_MAP_TILE					'0'
# define ID_MAP_SPACE					' '
# define ID_MAP_DOOR_CLOSED				'D'
# define ID_MAP_DOOR_OPENED				'O'
# define ID_MAP_SKY						'2'

# define IDS_MAP_SPRITE					"s"
# define IDS_MAP_ENTITY					"dicblpyrmof"
# define ID_MAP_PLAYER					'P'
# define ID_MAP_ENTITY					'e'

# define ID_TEXTURE_NORTH				"NO"
# define ID_TEXTURE_SOUTH				"SO"
# define ID_TEXTURE_WEST				"WE"
# define ID_TEXTURE_EAST				"EA"
# define ID_TEXTURE_FLOOR				"F"
# define ID_TEXTURE_CEILING				"C"
# define ID_TEXTURE_DOOR				"D"
# define ID_TEXTURE_SPRITE				"S"

# define ID_TEXTURE_UI_PAUSE_BG			"UI_PAUSE_BG"
# define ID_TEXTURE_UI_PAUSE_LABEL		"UI_PAUSE_LABEL"
# define ID_TEXTURE_UI_PAUSE_BTNR_OFF	"UI_PAUSE_BTN_RESUME_OFF"
# define ID_TEXTURE_UI_PAUSE_BTNR_ON	"UI_PAUSE_BTN_RESUME_ON"
# define ID_TEXTURE_UI_PAUSE_BTNQ_OFF	"UI_PAUSE_BTN_QUIT_OFF"
# define ID_TEXTURE_UI_PAUSE_BTNQ_ON	"UI_PAUSE_BTN_QUIT_ON"

# define ID_TEXTURE_UI_GAMEOVER_BG		"UI_GAMEOVER_BG"
# define ID_TEXTURE_UI_GAMEOVER_LABEL	"UI_GAMEOVER_LABEL"
# define ID_TEXTURE_UI_GAMEOVER_BTN_OFF	"UI_GAMEOVER_BTN_QUIT_OFF"
# define ID_TEXTURE_UI_GAMEOVER_BTN_ON	"UI_GAMEOVER_BTN_QUIT_ON"

# define ID_TEXTURE_UI_WIN_BG			"UI_WIN_BG"
# define ID_TEXTURE_UI_WIN_LABEL		"UI_WIN_LABEL"
# define ID_TEXTURE_UI_WIN_TROPHY		"UI_WIN_TROPHY"
# define ID_TEXTURE_UI_WIN_BTN_OFF		"UI_WIN_BTN_QUIT_OFF"
# define ID_TEXTURE_UI_WIN_BTN_ON		"UI_WIN_BTN_QUIT_ON"

# define ID_TEXTURE_DEMON_WALK			"DEMON_WALK"
# define ID_TEXTURE_DEMON_PAIN			"DEMON_PAIN"
# define ID_TEXTURE_DEMON_ATTACK		"DEMON_ATTACK"
# define ID_TEXTURE_DEMON_DEATH			"DEMON_DEATH"
# define ID_TEXTURE_IMP_WALK			"IMP_WALK"
# define ID_TEXTURE_IMP_PAIN			"IMP_PAIN"
# define ID_TEXTURE_IMP_ATTACK			"IMP_ATTACK"
# define ID_TEXTURE_IMP_DEATH			"IMP_DEATH"
# define ID_TEXTURE_IMP_PROJ_LIVE		"IMP_PROJECTILE_LIVE"
# define ID_TEXTURE_IMP_PROJ_DEATH		"IMP_PROJECTILE_DEATH"
# define ID_TEXTURE_CACO_WALK			"CACO_WALK"
# define ID_TEXTURE_CACO_PAIN			"CACO_PAIN"
# define ID_TEXTURE_CACO_ATTACK			"CACO_ATTACK"
# define ID_TEXTURE_CACO_DEATH			"CACO_DEATH"
# define ID_TEXTURE_CACO_PROJ_LIVE		"CACO_PROJECTILE_LIVE"
# define ID_TEXTURE_CACO_PROJ_DEATH		"CACO_PROJECTILE_DEATH"
# define ID_TEXTURE_BOH_WALK			"BOH_WALK"
# define ID_TEXTURE_BOH_PAIN			"BOH_PAIN"
# define ID_TEXTURE_BOH_ATTACK			"BOH_ATTACK"
# define ID_TEXTURE_BOH_DEATH			"BOH_DEATH"
# define ID_TEXTURE_BOH_PROJ_LIVE		"BOH_PROJECTILE_LIVE"
# define ID_TEXTURE_BOH_PROJ_DEATH		"BOH_PROJECTILE_DEATH"
# define ID_TEXTURE_LOST_SOUL_WALK		"LOST_SOUL_WALK"
# define ID_TEXTURE_LOST_SOUL_DEATH		"LOST_SOUL_DEATH"
# define ID_TEXTURE_PAIN_ELEM_WALK		"PAIN_ELEM_WALK"
# define ID_TEXTURE_PAIN_ELEM_PAIN		"PAIN_ELEM_PAIN"
# define ID_TEXTURE_PAIN_ELEM_ATTACK	"PAIN_ELEM_ATTACK"
# define ID_TEXTURE_PAIN_ELEM_DEATH		"PAIN_ELEM_DEATH"
# define ID_TEXTURE_CYBER_WALK			"CYBER_WALK"
# define ID_TEXTURE_CYBER_PAIN			"CYBER_PAIN"
# define ID_TEXTURE_CYBER_ATTACK		"CYBER_ATTACK"
# define ID_TEXTURE_CYBER_DEATH			"CYBER_DEATH"
# define ID_TEXTURE_ROCKET_LIVE			"ROCKET_LIVE"
# define ID_TEXTURE_ROCKET_DEATH		"ROCKET_DEATH"
# define ID_TEXTURE_REV_WALK			"REV_WALK"
# define ID_TEXTURE_REV_PAIN			"REV_PAIN"
# define ID_TEXTURE_REV_PUNCH			"REV_PUNCH"
# define ID_TEXTURE_REV_DEATH			"REV_DEATH"
# define ID_TEXTURE_REV_SHOOT			"REV_SHOOT"
# define ID_TEXTURE_MANC_WALK			"MANC_WALK"
# define ID_TEXTURE_MANC_PAIN			"MANC_PAIN"
# define ID_TEXTURE_MANC_ATTACK			"MANC_ATTACK"
# define ID_TEXTURE_MANC_DEATH			"MANC_DEATH"
# define ID_TEXTURE_MANC_FIREBALL		"MANC_FIREBALL"
# define ID_TEXTURE_SERGEANT_WALK		"SERGEANT_WALK"
# define ID_TEXTURE_SERGEANT_PAIN		"SERGEANT_PAIN"
# define ID_TEXTURE_SERGEANT_ATTACK		"SERGEANT_ATTACK"
# define ID_TEXTURE_SERGEANT_DEATH		"SERGEANT_DEATH"
# define ID_TEXTURE_COMMANDO_WALK		"COMMANDO_WALK"
# define ID_TEXTURE_COMMANDO_PAIN		"COMMANDO_PAIN"
# define ID_TEXTURE_COMMANDO_ATTACK		"COMMANDO_ATTACK"
# define ID_TEXTURE_COMMANDO_DEATH		"COMMANDO_DEATH"
# define ID_TEXTURE_REV_PROJ_LIVE		"REV_PROJECTILE_LIVE"
# define ID_TEXTURE_REV_PROJ_DEATH		"REV_PROJECTILE_DEATH"

# define ID_TEXTURE_TARGET1				"W_TARGET1"
# define ID_TEXTURE_W1_HAND				"W1_HAND"
# define ID_TEXTURE_W1_PUNCH			"W1_PUNCH"
# define ID_TEXTURE_W2_PISTOL			"W2_PISTOL"
# define ID_TEXTURE_W3_CHAINGUN			"W3_CHAINGUN"
# define ID_TEXTURE_W4_BF_GUN			"W4_BF_GUN"
# define ID_TEXTURE_W5_PLASMA			"W5_PLASMA"
# define ID_TEXTURE_W6_SHOTGUN			"W6_SHOTGUN"
# define ID_TEXTURE_W7_ROCKET			"W7_ROCKET"
# define ID_TEXTURE_W8_CHAINSAW			"W8_CHAINSAW"

# define ID_TEXTURE_W_BUL_BASIC_LIVE	"W_BULLET_BASIC_LIVE"
# define ID_TEXTURE_W_BUL_BASIC_DEATH	"W_BULLET_BASIC_DEATH"
# define ID_TEXTURE_W_BUL_ROCKET_LIVE	"W_BULLET_ROCKET_LIVE"
# define ID_TEXTURE_W_BUL_ROCKET_DEATH	"W_BULLET_ROCKET_DEATH"
# define ID_TEXTURE_W_BUL_PLASMA_LIVE	"W_BULLET_PLASMA_LIVE"
# define ID_TEXTURE_W_BUL_PLASMA_DEATH	"W_BULLET_PLASMA_DEATH"

# define ID_TEXTURE_HUD_BG				"HUD_BG"
# define ID_TEXTURE_HUD_HEALTH_LBL		"HUD_HEALTH_LBL"
# define ID_TEXTURE_HUD_WEAPON_LBL		"HUD_WEAPON_LBL"

# define ID_TEXTURE_SKY					"SKY"

# define IDX_TXTR_N						0
# define IDX_TXTR_S						1
# define IDX_TXTR_W						2
# define IDX_TXTR_E						3
# define IDX_TXTR_FLOOR					4
# define IDX_TXTR_CEIL					5
# define IDX_TXTR_DOOR					6
# define IDX_TXTR_SPRITE				7
# define IDX_TXTR_UIP_BG				8
# define IDX_TXTR_UIP_LBL				9
# define IDX_TXTR_UIP_B1_ON				10
# define IDX_TXTR_UIP_B1_OFF			11
# define IDX_TXTR_UIP_B2_ON				12
# define IDX_TXTR_UIP_B2_OFF			13
# define IDX_TXTR_DEMON_WALK			14
# define IDX_TXTR_DEMON_PAIN			15
# define IDX_TXTR_DEMON_ATTACK			16
# define IDX_TXTR_DEMON_DEATH			17
# define IDX_TXTR_IMP_WALK				18
# define IDX_TXTR_IMP_PAIN				19
# define IDX_TXTR_IMP_ATTACK			20
# define IDX_TXTR_IMP_DEATH				21
# define IDX_TXTR_IMP_PROJ_LIVE			22
# define IDX_TXTR_IMP_PROJ_DEATH		23
# define IDX_TXTR_CACO_WALK				24
# define IDX_TXTR_CACO_PAIN				25
# define IDX_TXTR_CACO_ATTACK			26
# define IDX_TXTR_CACO_DEATH			27
# define IDX_TXTR_CACO_PROJ_LIVE		28
# define IDX_TXTR_CACO_PROJ_DEATH		29
# define IDX_TXTR_BOH_WALK				30
# define IDX_TXTR_BOH_PAIN				31
# define IDX_TXTR_BOH_ATTACK			32
# define IDX_TXTR_BOH_DEATH				33
# define IDX_TXTR_BOH_PROJ_LIVE			34
# define IDX_TXTR_BOH_PROJ_DEATH		35
# define IDX_TXTR_LOST_SOUL_WALK		36
# define IDX_TXTR_LOST_SOUL_DEATH		37
# define IDX_TXTR_PAIN_ELEM_WALK		38
# define IDX_TXTR_PAIN_ELEM_PAIN		39
# define IDX_TXTR_PAIN_ELEM_ATTACK		40
# define IDX_TXTR_PAIN_ELEM_DEATH		41
# define IDX_TXTR_CYBER_WALK			42
# define IDX_TXTR_CYBER_PAIN			43
# define IDX_TXTR_CYBER_ATTACK			44
# define IDX_TXTR_CYBER_DEATH			45
# define IDX_TXTR_ROCKET_LIVE			46
# define IDX_TXTR_ROCKET_DEATH			47
# define IDX_TXTR_REV_WALK				48
# define IDX_TXTR_REV_PAIN				49
# define IDX_TXTR_REV_PUNCH				50
# define IDX_TXTR_REV_DEATH				51
# define IDX_TXTR_REV_SHOOT				52
# define IDX_TXTR_MANC_WALK				53
# define IDX_TXTR_MANC_PAIN				54
# define IDX_TXTR_MANC_ATTACK			55
# define IDX_TXTR_MANC_DEATH			56
# define IDX_TXTR_MANC_FIREBALL			57
# define IDX_TXTR_SERGEANT_WALK			58
# define IDX_TXTR_SERGEANT_PAIN			59
# define IDX_TXTR_SERGEANT_ATTACK		60
# define IDX_TXTR_SERGEANT_DEATH		61
# define IDX_TXTR_COMMANDO_WALK			62
# define IDX_TXTR_COMMANDO_PAIN			63
# define IDX_TXTR_COMMANDO_ATTACK		64
# define IDX_TXTR_COMMANDO_DEATH		65
# define IDX_TXTR_REV_PROJ_LIVE			66
# define IDX_TXTR_REV_PROJ_DEATH		67

# define IDX_TXTR_TARGET1				68
# define IDX_TXTR_W1_HAND				69
# define IDX_TXTR_W1_PUNCH				70
# define IDX_TXTR_W2_PISTOL				71
# define IDX_TXTR_W3_CHAINGUN			72
# define IDX_TXTR_W4_BF_GUN				73
# define IDX_TXTR_W5_PLASMA				74
# define IDX_TXTR_W6_SHOTGUN			75
# define IDX_TXTR_W7_ROCKET				76
# define IDX_TXTR_W8_CHAINSAW			77

# define IDX_TXTR_W_BUL_BASIC_LIVE		78
# define IDX_TXTR_W_BUL_BASIC_DEATH		79
# define IDX_TXTR_W_BUL_ROCKET_LIVE		80
# define IDX_TXTR_W_BUL_ROCKET_DEATH	81
# define IDX_TXTR_W_BUL_PLASMA_LIVE		82
# define IDX_TXTR_W_BUL_PLASMA_DEATH	83

# define IDX_TXTR_HUD_BG				84
# define IDX_TXTR_HUD_HEALTH_LBL		85
# define IDX_TXTR_HUD_WEAPON_LBL		86

# define IDX_TXTR_UI_GAMEOVER_BG		87
# define IDX_TXTR_UI_GAMEOVER_LABEL		88
# define IDX_TXTR_UI_GAMEOVER_BTN_OFF	89
# define IDX_TXTR_UI_GAMEOVER_BTN_ON	90

# define IDX_TXTR_UI_WIN_BG				91
# define IDX_TXTR_UI_WIN_LABEL			92
# define IDX_TXTR_UI_WIN_TROPHY			93
# define IDX_TXTR_UI_WIN_BTN_OFF		94
# define IDX_TXTR_UI_WIN_BTN_ON			95

# define IDX_TXTR_SKY					96

# define ID_MAP_DEMON					'd'
# define ID_MAP_IMP						'i'
# define ID_MAP_CACO					'c'
# define ID_MAP_BOH						'b'
# define ID_MAP_LOST_SOUL				'l'
# define ID_MAP_PAIN_ELEM				'p'
# define ID_MAP_CYBER					'y'
# define ID_MAP_REV						'r'
# define ID_MAP_MANC					'm'
# define ID_MAP_COMMANDO				'o'
# define ID_MAP_SERGEANT				'f'

# define MAP_EXTENSION					".cub"
# define MAP_ALLOWED_CHARS				" 012spdicblayrmofNSEWD"
# define MAP_NB_IDS						97

# define MAP_MOVING_CHARS				"PNSEWe"

# define MAP_BG_DARK_FACTOR				0.6f
# define MAP_DRAW_SIZE_RATIO			0.95f
# define MAP_DRAW_ELT_MAX_RADIUS		8
# define MAP_DRAW_MIN_TILE_SIZE			2
# define MAP_DRAW_COL_BG				0x002801
# define MAP_DRAW_COL_DECORATION		0x007000
# define MAP_DRAW_COL_SPACE				0x002801
# define MAP_DRAW_COL_WALL				0x09BB17
# define MAP_DRAW_COL_TILE				0x006700
# define MAP_DRAW_COL_DOOR1				0x00FF00
# define MAP_DRAW_COL_DOOR2				0x006700
# define MAP_DRAW_COL_PLAYER			0xFFFF00
# define MAP_DRAW_COL_RAYS				0x008700
# define MAP_DRAW_COL_ENNEMIES			0xFF0000

typedef struct s_game		t_game;
typedef struct s_map		t_map;
typedef struct s_map_draw	t_map_draw;
typedef struct s_vector		t_vector;
typedef struct s_door		t_door;
typedef struct s_ray		t_ray;
typedef struct s_sprite		t_sprite;
typedef struct s_list		t_list;
typedef struct s_mlx_coords	t_mlx_coords;

struct s_map_draw
{
	int				tile_size;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	t_mlx_coords	nb_tiles;
	int				element_radius;
};

struct s_map
{
	char			**tiles;
	size_t			*lines_lengths;
	size_t			lines_count;
	char			*textures[MAP_NB_IDS];
	t_mlx_coords	texture_size[MAP_NB_IDS];
	t_map_draw		draw;
};

// Map functions
bool	read_map(t_map *map, char *filename,
			t_animation anim[MAP_NB_IDS]);
bool	is_map_valid(t_map *map);
bool	read_elements(t_map *map, int fd, t_animation anim[MAP_NB_IDS]);
bool	is_in_bounds(t_vector *position, t_map *map);
bool	is_character(t_vector *position, t_map *map, char character);
bool	check_extension(char *filename, char *extension);
void	free_map(t_map *map);
bool	is_walkable(t_map *map, t_mlx_coords *coords);
bool	get_elem_into_list(t_game *game, t_list **dest, char *ids,
			void *add_elem(t_game *, float, float, char));
void	update_map(t_map *map, t_game *game);
void	init_identifier(char **identifier);
void	init_weapons_identifier(char **identifier);
void	init_hud_identifier(char **identifier);

// Draw map functions
void	draw_map(t_map_draw *map_draw, t_map *map, t_game *game);
void	draw_map_entities(t_map_draw *draw, t_game *game);
bool	init_map_draw(t_map_draw *map_draw, t_map *map, t_game *game);

#endif
