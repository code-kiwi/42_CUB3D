/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamewon_handlers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:39:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 01:00:59 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "ui_bonus.h"

void	mouse_release_gamewon_handler(int x, int y, t_game *game)
{
	t_button	*quit_btn;

	quit_btn = &game->uis.win.buttons[0];
	if (is_over_button(quit_btn, x, y))
		quit_btn->callback((void *)game);
}

void	mouse_move_gamewon_handler(int x, int y, t_game *game)
{
	t_button	*quit_btn;

	quit_btn = &game->uis.win.buttons[0];
	if (is_over_button(quit_btn, x, y))
		quit_btn->texture_active = quit_btn->texture_on;
	else
		quit_btn->texture_active = quit_btn->texture_off;
}
