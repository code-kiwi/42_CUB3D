/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/14 00:21:05 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_vector	t_vector;

struct s_map
{
	char	**tiles;
	size_t	*lines_lengths;
	size_t	lines_count;
	char	*textures[6];
};

// Map functions
bool		read_map(t_game *game, char *filename);
bool		is_map_valid(t_map *map);
bool		read_elements(t_game *game, int fd);
bool		is_in_bounds(t_vector *position, t_map *map);

#endif
