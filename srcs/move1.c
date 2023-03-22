/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:15:21 by ma1iik            #+#    #+#             */
/*   Updated: 2023/03/18 09:43:07 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_release(int key, t_data *data)
{
	(void)data;
	if (key == ESC)
		exit(0);
	return (0);
}

void	draw_text(t_data *data)
{
	int		y;
	int		x;

	y = data->pl_tx_y;
	while (y < data->pl_tx_y + TX_L)
	{
		x = data->pl_tx_x;
		while (x < data->pl_tx_x + TX_L)
		{
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int	check_wall_around(t_data *data, int i, int j, int radius)
{
	(void)data;
	(void)i;
	(void)j;
	(void)radius;
	return (0);
}

double	find_wl(t_data *data)
{
	if (fabs(data->x_fnl - data->pl_tx_x) >= fabs(data->y_fnl - data->pl_tx_y))
		return (fabs(data->pl_tx_x - data->x_fnl));
	else
		return (fabs(data->pl_tx_y - data->y_fnl));
}

int	ft_action(int key, t_data *data)
{
	if (key == KEY_W)
		move_up(data, 0, 0);
	else if (key == KEY_S)
		move_down(data);
	else if (key == KEY_A)
		move_left(data);
	else if (key == KEY_D)
		move_right(data);
	else if (key == ARROW_L)
		move_angle_l(data);
	else if (key == ARROW_R)
		move_angle_r(data);
	return (0);
}
