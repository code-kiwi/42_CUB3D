/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_data_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:01:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"

/**
 * @brief Destroys the given t_cub_data
 * @param data The structure to destroy
*/
void	t_cub_data_destroy(t_cub_data *data)
{
	if (data == NULL)
		return ;
	t_mlx_destroy(&data->mlx);
}
