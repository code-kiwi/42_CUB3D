/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:42:52 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 09:30:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sign(float value)
{
	if (value < 0)
		return (-1);
	return (1);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
