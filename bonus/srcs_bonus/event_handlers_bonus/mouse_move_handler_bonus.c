/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/26 07:38:41 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"
#include "ui_bonus.h"

void	mouse_move_pause_handler(int x, int y, t_game *game)
{
	t_button	*resume_btn;
	t_button	*quit_btn;

	resume_btn = &game->ui_pause.buttons[0];
	quit_btn = &game->ui_pause.buttons[1];
	if (is_over_button(resume_btn, x, y))
		resume_btn->texture_active = &resume_btn->texture_on;
	else
		resume_btn->texture_active = &resume_btn->texture_off;
	if (is_over_button(quit_btn, x, y))
		quit_btn->texture_active = &quit_btn->texture_on;
	else
		quit_btn->texture_active = &quit_btn->texture_off;
}

int	mouse_move_handler(int x, int y, t_game *game)
{
	if (game->pause)
		mouse_move_pause_handler(x, y, game);
	return (1);
}
