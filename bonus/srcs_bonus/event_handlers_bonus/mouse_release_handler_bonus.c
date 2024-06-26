/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/26 07:38:33 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"
#include "ui_bonus.h"

void	mouse_release_pause_handler(int x, int y, t_game *game)
{
	t_button	*resume_btn;
	t_button	*quit_btn;

	resume_btn = &game->ui_pause.buttons[0];
	quit_btn = &game->ui_pause.buttons[1];
	if (is_over_button(resume_btn, x, y))
		resume_btn->callback((void *)game);
	if (is_over_button(quit_btn, x, y))
		quit_btn->callback((void *)game);
}

int	mouse_release_handler(int button, int x, int y, t_game *game)
{
	if (button == MOUSE_LEFT && game->pause)
		mouse_release_pause_handler(x, y, game);
	return (1);
}
