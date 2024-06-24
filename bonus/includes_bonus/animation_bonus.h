/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:35:15 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 13:22:09 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

typedef struct s_list	t_list;
typedef struct s_image	t_image;

void	destroy_animation(t_list *anim, void *mlx_ptr, bool is_circular);
t_list	*create_animation(t_image *texture, void *mlx_ptr);

#endif // !ANIMATION_BONUS_H