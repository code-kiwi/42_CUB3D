/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:35:15 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 20:13:34 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

typedef struct s_list	t_list;
typedef struct s_image	t_image;

# define ANIMATION_UPDATE	0.1

void	destroy_animation(t_list *anim, void *mlx_ptr, bool is_circular);
t_list	*create_animation(t_image *texture, void *mlx_ptr);
void	update_animations(t_game *game, float delta_time);

#endif
