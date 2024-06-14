/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:00 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 15:01:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_H
# define EVENT_HANDLERS_H

typedef struct s_game	t_game;

bool	add_event_handlers(t_game *game);
int		destroy_handler(t_game *game);
int		key_up_handler(int key, t_game *data);
int		key_down_handler(int key, t_game *data);

#endif