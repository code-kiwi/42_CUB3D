/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:02:00 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/19 12:01:31 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

typedef struct s_vector	t_vector;

struct s_vector
{
	float	x;
	float	y;
};

// t_vector functions
void		t_vector_copy(t_vector *dest, t_vector *src);
t_vector	t_vector_error(void);
void		t_vector_print(char *prefix, t_vector *vector);
void		t_vector_init(t_vector *vector, float x, float y);
void		t_vector_get_slope(t_vector *slope, float angle_rad);

#endif