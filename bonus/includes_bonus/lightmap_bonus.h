/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightmap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:14:23 by brappo            #+#    #+#             */
/*   Updated: 2024/09/11 05:14:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTMAP_BONUS_H
# define LIGHTMAP_BONUS_H

# define LIGHTMAP_TILE_RATIO 10

t_vector	*get_lights_position(t_map *map, size_t light_count);
size_t		count_lights(t_map *map);
bool		create_lightmap(t_map *map, t_game *game);

#endif // !LIGHTMAP_BONUS_H