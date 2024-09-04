/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/04 21:03:18 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>


#include "libft.h"


#include "cub3d_bonus.h"

/* **** */
static void	init_uis_ids1(char *identifiers[UI_NB_TEXTURES])
{
	identifiers[UI_TXTR_IDX_PAUSE_BG] = UI_TXTR_PAUSE_BG;
	identifiers[UI_TXTR_IDX_PAUSE_LABEL] = UI_TXTR_PAUSE_LABEL;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_RESUME_OFF] = \
		UI_TXTR_PAUSE_BTN_RESUME_OFF;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_RESUME_ON] = UI_TXTR_PAUSE_BTN_RESUME_ON;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_QUIT_OFF] = UI_TXTR_PAUSE_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_PAUSE_BTN_QUIT_ON] = UI_TXTR_PAUSE_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_GAMEOVER_BG] = UI_TXTR_GAMEOVER_BG;
	identifiers[UI_TXTR_IDX_GAMEOVER_LABEL] = UI_TXTR_GAMEOVER_LABEL;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_OFF] = \
		UI_TXTR_GAMEOVER_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_ON] = \
		UI_TXTR_GAMEOVER_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_RESTART_OFF] = \
		UI_TXTR_GAMEOVER_BTN_RESTART_OFF;
	identifiers[UI_TXTR_IDX_GAMEOVER_BTN_RESTART_ON] = \
		UI_TXTR_GAMEOVER_BTN_RESTART_ON;
	identifiers[UI_TXTR_IDX_WIN_BG] = UI_TXTR_WIN_BG;
	identifiers[UI_TXTR_IDX_WIN_LABEL] = UI_TXTR_WIN_LABEL;
	identifiers[UI_TXTR_IDX_WIN_TROPHY] = UI_TXTR_WIN_TROPHY;
	identifiers[UI_TXTR_IDX_WIN_BTN_QUIT_OFF] = UI_TXTR_WIN_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_WIN_BTN_QUIT_ON] = UI_TXTR_WIN_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_HOME_BG] = UI_TXTR_HOME_BG;
	identifiers[UI_TXTR_IDX_HOME_LABEL] = UI_TXTR_HOME_LABEL;
	identifiers[UI_TXTR_IDX_HOME_BTN_PLAY_OFF] = UI_TXTR_HOME_BTN_PLAY_OFF;
}

static void	init_uis_ids2(char *identifiers[UI_NB_TEXTURES])
{
	identifiers[UI_TXTR_IDX_HOME_BTN_PLAY_ON] = UI_TXTR_HOME_BTN_PLAY_ON;
	identifiers[UI_TXTR_IDX_HOME_BTN_QUIT_OFF] = UI_TXTR_HOME_BTN_QUIT_OFF;
	identifiers[UI_TXTR_IDX_HOME_BTN_QUIT_ON] = UI_TXTR_HOME_BTN_QUIT_ON;
	identifiers[UI_TXTR_IDX_LVL_BG] = UI_TXTR_LVL_BG;
	identifiers[UI_TXTR_IDX_LVL_LABEL] = UI_TXTR_LVL_LABEL;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL1_OFF] = UI_TXTR_LVL_BTN_LVL1_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL1_ON] = UI_TXTR_LVL_BTN_LVL1_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL2_OFF] = UI_TXTR_LVL_BTN_LVL2_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL2_ON] = UI_TXTR_LVL_BTN_LVL2_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL3_OFF] = UI_TXTR_LVL_BTN_LVL3_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL3_ON] = UI_TXTR_LVL_BTN_LVL3_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL4_OFF] = UI_TXTR_LVL_BTN_LVL4_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL4_ON] = UI_TXTR_LVL_BTN_LVL4_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL5_OFF] = UI_TXTR_LVL_BTN_LVL5_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_LVL5_ON] = UI_TXTR_LVL_BTN_LVL5_ON;
	identifiers[UI_TXTR_IDX_LVL_BTN_PREV_OFF] = UI_TXTR_LVL_BTN_PREV_OFF;
	identifiers[UI_TXTR_IDX_LVL_BTN_PREV_ON] = UI_TXTR_LVL_BTN_PREV_ON;
}

bool	init_uis_txtr_identifiers(char *identifiers[UI_NB_TEXTURES])
{
	if (identifiers == NULL)
		return (false);
	init_uis_ids1(identifiers);
	init_identifier2(identifiers);
}

/* **** */

static void	free_ui_textures(void *mlx_ptr, t_image *textures[UI_NB_TEXTURES])
{
	size_t	i;

	if (textures == NULL)
		return ;
	i = 0;
	while (i < UI_NB_TEXTURES)
	{
		if (textures[i] != NULL)
		{
			t_image_destroy(mlx_ptr, textures[i], true);
			textures[i] = NULL;
		}
		i++;
	}	
}

/* **** */	

static bool	read_ui_element(
	char *identifiers[UI_NB_TEXTURES],
	t_image *textures[UI_NB_TEXTURES],
	char *line,
	void *mlx_ptr
)
{
	ssize_t	index;
	char	**split;
	t_image	*img;

	split = ft_split(line, " ");
	if (array_length((void **) split) != 2)
	{
		ft_free_str_array(&split);
		return (error_print(ERR_UIS_READ_ELEMENT), false);
	}
	index = find_str_in_array(identifiers, split[0], UI_NB_TEXTURES);
	if (index == -1)
	{
		error_print_string(ERR_UIS_IDENTIFIER, split[0]);
		return (ft_free_str_array(&split), false);
	}
	if (!t_image_import_file(img, split[1], mlx_ptr, NULL))
	{
		error_print_string(ERR_UIS_IMG_INIT, split[1]);
		return (ft_free_str_array(&split), false);
	}
	ft_free_str_array(&split);
	textures[index] = img;
	identifiers[index] = NULL;
	return (true);
}

bool	read_ui_elements(
	char *identifiers[UI_NB_TEXTURES],
	t_image *textures[UI_NB_TEXTURES],
	int fd,
	void *mlx_ptr
)
{
	char	*line;
	size_t	nb_read;
	size_t	count;

	if (textures == NULL || fd < 0)
		return (error_print(ERR_UIS_CREATION), false);
	count = 0;
	while (count < UI_NB_TEXTURES)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error_print(ERR_UIS_READ), false);
		remove_last_breakline(line);
		if (!read_ui_element(identifiers, textures, line, mlx_ptr))
		{
			free(line);
			return (false);
		}
		free(line);
		count++;
	}
	return (true);
}

/* **** */

bool	uis_init_textures(t_game *game, t_game_uis *uis)
{
	char	*identifiers[UI_NB_TEXTURES];
	int		fd;

	if (game == NULL || uis == NULL || game->mlx.mlx_ptr == NULL)
		return (error_print(ERR_UIS_CREATION), false);
	ft_bzero(uis, sizeof(t_game_uis));
	if (!init_uis_txtr_identifiers(identifiers))
		return (error_print(ERR_UIS_IDS_CREATION), false);
	fd = open(UI_TEXTURES_PATH, O_RDONLY);
	if (fd == -1)
		return (error_print(ERR_UIS_IDS_CREATION), false);
	if (!read_ui_elements(identifiers, uis->textures, fd, game->mlx.mlx_ptr))
	{
		free_ui_textures(game->mlx.mlx_ptr, uis->textures);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}


/* **** */

bool	init_game_uis(t_game *game, t_game_uis *uis)
{
	if (game == NULL || uis == NULL)
		return (error_print(ERR_UIS_CREATION), false);
	// Get all ui textures
	if (!uis_init_textures(game, uis))
		return (false);

	// Init the uis
	return (true);
}