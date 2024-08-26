/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_handlers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:39:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/08/26 15:51:36 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "ui_bonus.h"

void	mouse_release_gameover_handler(int x, int y, t_game *game)
{
	t_button	*quit_btn;

	quit_btn = &game->ui_game_over.buttons[0];
	if (is_over_button(quit_btn, x, y))
		quit_btn->callback((void *)game);
}

void	mouse_move_gameover_handler(int x, int y, t_game *game)
{
	t_button	*quit_btn;

	quit_btn = &game->ui_game_over.buttons[0];
	if (is_over_button(quit_btn, x, y))
		quit_btn->texture_active = quit_btn->texture_on;
	else
		quit_btn->texture_active = quit_btn->texture_off;
}