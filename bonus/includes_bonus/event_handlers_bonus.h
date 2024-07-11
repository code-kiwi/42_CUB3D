/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:00 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/10 10:47:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_BONUS_H
# define EVENT_HANDLERS_BONUS_H

# define MOTION_X_DECREASE_FACTOR   20.0f

typedef struct s_game	t_game;

bool	add_event_handlers(t_game *game);
int		destroy_handler(t_game *game);
int		key_release_handler(int key, t_game *game);
int		key_press_handler(int key, t_game *game);
int		mouse_move_handler(int x, int y, t_game *game);
int		mouse_press_handler(int button, int x, int y, t_game *game);
int		mouse_release_handler(int button, int x, int y, t_game *game);
void	mouse_release_pause_handler(int x, int y, t_game *game);
void	mouse_move_pause_handler(int x, int y, t_game *game);

#endif
