/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:15:21 by ma1iik            #+#    #+#             */
/*   Updated: 2023/03/18 09:51:25 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_angle_l(t_data *data)
{
	data->pa = fmod(data->pa + M_PI / 36, 2 * M_PI);
	if (data->pa > 2 * M_PI)
		data->pa -= 2 * M_PI;
	cast_rays1(data);
	return ;
}

int	the_return(t_data *data)
{
	if (ft_fill_map2(data) == WRONG || ft_fill_map3(data) == WRONG)
		return (WRONG);
	return (RIGHT);
}
