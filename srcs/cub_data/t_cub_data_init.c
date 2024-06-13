/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:02:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/**
 * @brief Initializes the given t_cub_data
 * @param data The structure to init
 * @return true on SUCCESS, false on ERROR
*/
bool	t_cub_data_init(t_cub_data *data)
{
	if (data == NULL)
		return (false);
	ft_memset(data, 0, sizeof(t_cub_data));
	return (true);
}
