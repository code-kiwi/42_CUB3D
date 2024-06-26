/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:00 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 20:14:00 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_BONUS_H
# define EVENT_HANDLERS_BONUS_H

typedef struct s_game	t_game;

bool	add_event_handlers(t_game *game);
int		destroy_handler(t_game *game);
int		key_release_handler(int key, t_game *data);
int		key_press_handler(int key, t_game *data);

#endif
