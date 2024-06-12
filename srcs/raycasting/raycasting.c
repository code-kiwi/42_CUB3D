/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:59:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/12 11:05:53 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

t_vector	calculate_unit_length(t_vector slope)
{
	t_vector	unit_length;

	unit_length.x = 
}

t_vector	raycast(t_vector position, t_vector slope)
{
	t_vector	unit_length;

	unit_length = calculate_unit_length(slope);
}
