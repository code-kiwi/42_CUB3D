/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightmaps_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:45:43 by brappo            #+#    #+#             */
/*   Updated: 2024/09/09 06:31:15 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTMAPS_BONUS
# define LIGHTMAPS_BONUS

# include <stddef.h>

# define LIGHTMAP_TILE_RATIO	10
# define LIGHT_RADIUS			10

void	calculate_lightning(char **lightmap, size_t x, size_t y, t_game *game);

#endif // !LIGHTMAPS_BONUS