/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:00 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:53:48 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_H
# define EVENT_HANDLERS_H

typedef struct s_cub_data	t_cub_data;

bool	add_event_handlers(t_cub_data *data);
int		destroy_handler(t_cub_data *data);
int		keyboard_handler(int key, t_cub_data *data);

#endif