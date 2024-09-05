/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:39:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/05 01:01:18 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_release_home_handler(int x, int y, t_game *game)
{
	t_button	*play_btn;
	t_button	*quit_btn;

	play_btn = &game->uis.home.buttons[0];
	quit_btn = &game->uis.home.buttons[1];
	if (is_over_button(play_btn, x, y))
		play_btn->callback((void *)game);
	if (is_over_button(quit_btn, x, y))
		quit_btn->callback((void *)game);
}

void	mouse_move_home_handler(int x, int y, t_game *game)
{
	t_button	*play_btn;
	t_button	*quit_btn;

	play_btn = &game->uis.home.buttons[0];
	quit_btn = &game->uis.home.buttons[1];
	if (is_over_button(play_btn, x, y))
		play_btn->texture_active = play_btn->texture_on;
	else
		play_btn->texture_active = play_btn->texture_off;
	if (is_over_button(quit_btn, x, y))
		quit_btn->texture_active = quit_btn->texture_on;
	else
		quit_btn->texture_active = quit_btn->texture_off;
}
