/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:33 by brappo            #+#    #+#             */
/*   Updated: 2024/07/01 10:10:37 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_BONUS_H
# define ITEM_BONUS_H

typedef struct s_image	t_image;
typedef struct s_item	t_item;

struct s_item
{
	void	(*use_item)(void *);
	t_image	*texture;
};

#endif // !ITEM_BONUS_H