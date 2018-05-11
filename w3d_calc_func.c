/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_calc_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:52:18 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/14 15:54:55 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_lenght_ray(t_img *im)
{
	if (im->pos.var_pos.ray_dir_x < 0)
	{
		im->pos.var_pos.step_x = -1;
		im->pos.var_pos.side_dist_x = (im->pos.var_pos.ray_pos_x -
			im->col_y.map_x) * im->pos.var_pos.delta_dist_x;
	}
	else
	{
		im->pos.var_pos.step_x = 1;
		im->pos.var_pos.side_dist_x = (im->col_y.map_x + 1.0 -
			im->pos.var_pos.ray_pos_x) * im->pos.var_pos.delta_dist_x;
	}
	if (im->pos.var_pos.ray_dir_y < 0)
	{
		im->pos.var_pos.step_y = -1;
		im->pos.var_pos.side_dist_y = (im->pos.var_pos.ray_pos_y -
			im->col_y.map_y) * im->pos.var_pos.delta_dist_y;
	}
	else
	{
		im->pos.var_pos.step_y = 1;
		im->pos.var_pos.side_dist_y = (im->col_y.map_y + 1.0 -
			im->pos.var_pos.ray_pos_y) * im->pos.var_pos.delta_dist_y;
	}
}

void	cyrcl_dist(t_img *im)
{
	while (im->pos.var_pos.hit == 0)
	{
		if (im->pos.var_pos.side_dist_x < im->pos.var_pos.side_dist_y)
		{
			im->pos.var_pos.side_dist_x += im->pos.var_pos.delta_dist_x;
			im->col_y.map_x += im->pos.var_pos.step_x;
			im->pos.var_pos.side = 0;
		}
		else
		{
			im->pos.var_pos.side_dist_y += im->pos.var_pos.delta_dist_y;
			im->col_y.map_y += im->pos.var_pos.step_y;
			im->pos.var_pos.side = 1;
		}
		if (im->world_map[im->col_y.map_y][im->col_y.map_x] > 0)
			im->pos.var_pos.hit = 1;
	}
}

void	calc_dist_on_cam(t_img *im)
{
	if (im->pos.var_pos.side == 0)
		im->pos.var_pos.perp_wall_dist = (im->col_y.map_x -
			im->pos.var_pos.ray_pos_x + (1 - im->pos.var_pos.step_x) /
			2) / im->pos.var_pos.ray_dir_x;
	else
		im->pos.var_pos.perp_wall_dist = (im->col_y.map_y -
			im->pos.var_pos.ray_pos_y + (1 - im->pos.var_pos.step_y) /
				2) / im->pos.var_pos.ray_dir_y;
}

void	calc_start_end_strip(t_img *im)
{
	im->col_y.begin_y = -im->pos.var_pos.line_height / 2 + H / 2;
	if (im->col_y.begin_y < 0)
		im->col_y.begin_y = 0;
	im->col_y.end_y = im->pos.var_pos.line_height / 2 + H / 2;
	if (im->col_y.end_y >= H)
		im->col_y.end_y = H - 1;
}
