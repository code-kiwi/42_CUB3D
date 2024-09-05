/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_selection_handlers_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:39:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 01:00:29 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_release_level_selection_handler(int x, int y, t_game *game)
{
	t_button	*lvl_btns[UI_LVL_NB_BTN];
	size_t		i;

	i = 0;
	while (i < UI_LVL_NB_BTN)
	{
		lvl_btns[i] = &game->uis.level_selection.buttons[i];
		if (is_over_button(lvl_btns[i], x, y))
		{
			lvl_btns[i]->callback((void *)game);
			break ;
		}
		i++;
	}
}

void	mouse_move_level_selection_handler(int x, int y, t_game *game)
{
	t_button	*lvl_btns[UI_LVL_NB_BTN];
	size_t		i;

	i = 0;
	while (i < UI_LVL_NB_BTN)
	{
		lvl_btns[i] = &game->uis.level_selection.buttons[i];
		if (is_over_button(lvl_btns[i], x, y))
			lvl_btns[i]->texture_active = lvl_btns[i]->texture_on;
		else
			lvl_btns[i]->texture_active = lvl_btns[i]->texture_off;
		i++;
	}
}
