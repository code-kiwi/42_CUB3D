/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightmaps_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:45:43 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 13:16:24 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTMAPS_BONUS_H
# define LIGHTMAPS_BONUS_H

# include <stddef.h>

# define LIGHTMAP_TILE_RATIO	10
# define LIGHT_RADIUS			10

typedef struct s_game	t_game;

void	calculate_lightning(float **lightmap, size_t x, size_t y, t_game *game);

#endif // !LIGHTMAPS_BONUS_H