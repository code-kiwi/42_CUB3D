/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:21:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 09:27:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "mlx_api.h"

typedef struct s_ui		t_ui;
typedef struct s_button	t_button;

struct s_ui
{
	t_mlx_coords	pos;
	int				width;
	int				height;
	t_image			*texture;
	t_button		*buttons;
};

struct s_button
{
	t_mlx_coords	pos;
	int				width;
	int				height;
	t_image			*texture;
	void			(*callback)(void *);
};

// ui functions

#endif