/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:56:33 by brappo            #+#    #+#             */
/*   Updated: 2024/07/01 15:35:02 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_BONUS_H
# define ITEM_BONUS_H

# include <sys/types.h>

typedef struct s_image	t_image;
typedef struct s_item	t_item;
typedef struct s_game	t_game;

struct s_item
{
	void	(*use_item)(t_game *);
	t_image	*texture;
	ssize_t	remaining_usage;
};

#endif // !ITEM_BONUS_H