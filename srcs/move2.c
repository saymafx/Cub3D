/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:15:21 by ma1iik            #+#    #+#             */
/*   Updated: 2023/03/18 09:46:42 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_data *data, double i, double j)
{
	double	delta_x;
	double	delta_y;
	double	wl;

	wl = find_wl(data);
	delta_x = (data->x_fnl - data->pl_tx_x) / wl;
	delta_y = (data->y_fnl - data->pl_tx_y) / wl;
	i = data->pl_tx_x + (delta_x * MOVE);
	j = data->pl_tx_y + (delta_y * MOVE);
	if (data->r_distance <= (sqrt((pow(data->pl_tx_x - i, 2)
					+ pow(data->pl_tx_y - j, 2)))))
	{
		i = data->x_fnl - (delta_x / 6);
		j = data->y_fnl - delta_y / 6;
	}
	if (check_wall_around(data, i, j, 0) == 0)
	{
		if (data->pl_tx_x / TX_L != i / TX_L
			|| data->pl_tx_y / TX_L != j / TX_L)
			change_pos(data, j, i);
		data->pl_tx_x = i;
		data->pl_tx_y = j;
		cast_rays1(data);
	}
}

void	move_down(t_data *data)
{
	int		i;
	int		j;
	double	delta_x;
	double	delta_y;
	double	wl;

	if (fabs(data->x_fnl - data->pl_tx_x) >= fabs(data->y_fnl - data->pl_tx_y))
		wl = fabs(data->pl_tx_x - data->x_fnl);
	else
		wl = fabs(data->pl_tx_y - data->y_fnl);
	delta_x = ((data->pl_tx_x - data->x_fnl) / wl);
	delta_y = ((data->pl_tx_y - data->y_fnl) / wl);
	i = data->pl_tx_x + (delta_x * MOVE);
	j = data->pl_tx_y + (delta_y * MOVE);
	if (data->map[j / TX_L][i / TX_L] == '1')
		return ;
	if (check_wall_around(data, i, j, 0) == 0)
	{
		if (data->pl_tx_x / TX_L != i / TX_L
			|| data->pl_tx_y / TX_L != j / TX_L)
			change_pos(data, j, i);
		data->pl_tx_x += delta_x * MOVE;
		data->pl_tx_y += delta_y * MOVE;
		cast_rays1(data);
	}
}

void	move_left(t_data *data)
{
	int		i;
	int		j;
	double	delta_x;
	double	delta_y;
	double	wl;

	if (fabs(data->x_fnl - data->pl_tx_x) >= fabs(data->y_fnl - data->pl_tx_y))
		wl = fabs(data->pl_tx_x - data->x_fnl);
	else
		wl = fabs(data->pl_tx_y - data->y_fnl);
	delta_x = ((data->y_fnl - data->pl_tx_y) / wl);
	delta_y = ((data->pl_tx_x - data->x_fnl) / wl);
	i = data->pl_tx_x + (delta_x * MOVE);
	j = data->pl_tx_y + (delta_y * MOVE);
	if (data->map[j / TX_L][i / TX_L] == '1')
		return ;
	if (check_wall_around(data, i, j, 0) == 0)
	{
		if (data->pl_tx_x / TX_L != i / TX_L
			|| data->pl_tx_y / TX_L != j / TX_L)
			change_pos(data, j, i);
		data->pl_tx_x += delta_x * MOVE;
		data->pl_tx_y += delta_y * MOVE;
		cast_rays1(data);
	}
}

void	move_right(t_data *data)
{
	int		i;
	int		j;
	double	delta_x;
	double	delta_y;
	double	wl;

	if (fabs(data->x_fnl - data->pl_tx_x) >= fabs(data->y_fnl - data->pl_tx_y))
		wl = fabs(data->pl_tx_x - data->x_fnl);
	else
		wl = fabs(data->pl_tx_y - data->y_fnl);
	delta_x = ((data->pl_tx_y - data->y_fnl) / wl);
	delta_y = ((data->x_fnl - data->pl_tx_x) / wl);
	i = data->pl_tx_x + (delta_x * MOVE);
	j = data->pl_tx_y + (delta_y * MOVE);
	if (data->map[j / TX_L][i / TX_L] == '1')
		return ;
	if (check_wall_around(data, i, j, 0) == 0)
	{
		if (data->pl_tx_x / TX_L != i / TX_L
			|| data->pl_tx_y / TX_L != j / TX_L)
			change_pos(data, j, i);
		data->pl_tx_x += delta_x * MOVE;
		data->pl_tx_y += delta_y * MOVE;
		cast_rays1(data);
	}
}

void	move_angle_r(t_data *data)
{
	data->pa -= M_PI / 36;
	if (data->pa < 0)
		data->pa += 2 * M_PI;
	cast_rays1(data);
	return ;
}
