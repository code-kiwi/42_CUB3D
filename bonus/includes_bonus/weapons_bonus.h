/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:09:22 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 13:01:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_BONUS_H
# define WEAPONS_BONUS_H

# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api_bonus.h"

# define NB_TOT_WEAPONS	2
# define IDX_W1_HAND	0
# define IDX_W2_PISTOL	1

typedef struct s_weapon	t_weapon;
typedef struct s_list	t_list;
typedef struct s_game	t_game;

struct s_weapon
{
	t_image	*frame;
	t_list	*frames_action;
	t_list	*frames_reload;
	t_list	*frames_bullet;
	t_image	*target;
	size_t	num_loads;
	size_t	load_capacity;
	size_t	remaining_use;
	bool	is_limited;
	bool	is_use_continuous;
	char	id;
};

// Weapon functions
bool	init_weapons(t_game *game);

# endif
