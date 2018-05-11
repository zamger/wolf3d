/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_contr_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:06:40 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/14 12:06:40 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		forward_cam(t_img *im)
{
	if (im->world_map[(int)(im->pos.pos_y)]
		[(int)(im->pos.pos_x + im->pos.dir_x * im->pos.move_speed)] == 0)
		im->pos.pos_x += im->pos.dir_x * im->pos.move_speed;
	if (im->world_map
			[(int)(im->pos.pos_y + im->pos.dir_y * im->pos.move_speed)]
				[(int)(im->pos.pos_x)] == 0)
		im->pos.pos_y += im->pos.dir_y * im->pos.move_speed;
}

void		back_cam(t_img *im)
{
	if (im->world_map[(int)im->pos.pos_y]
			[(int)(im->pos.pos_x - im->pos.dir_x * im->pos.move_speed)] == 0)
		im->pos.pos_x -= im->pos.dir_x * im->pos.move_speed;
	if (im->world_map
			[(int)(im->pos.pos_y - im->pos.dir_y * im->pos.move_speed)]
				[(int)im->pos.pos_x] == 0)
		im->pos.pos_y -= im->pos.dir_y * im->pos.move_speed;
}

void		str_cam(t_img *im, char ch)
{
	if (ch == 'r')
	{
		if (im->world_map[(int)(im->pos.pos_y)]
				[(int)(im->pos.pos_x + im->pos.dir_y * im->pos.move_speed)]
					== 0)
			im->pos.pos_x += im->pos.dir_y * im->pos.move_speed;
		if (im->world_map
				[(int)(im->pos.pos_y - im->pos.dir_x * im->pos.move_speed)]
					[(int)im->pos.pos_x] == 0)
			im->pos.pos_y -= im->pos.dir_x * im->pos.move_speed;
	}
	else if (ch == 'l')
	{
		if (im->world_map[(int)(im->pos.pos_y)]
				[(int)(im->pos.pos_x - im->pos.dir_y * im->pos.move_speed)]
					== 0)
			im->pos.pos_x -= im->pos.dir_y * im->pos.move_speed;
		if (im->world_map
				[(int)(im->pos.pos_y + im->pos.dir_x * im->pos.move_speed)]
					[(int)im->pos.pos_x] == 0)
			im->pos.pos_y += im->pos.dir_x * im->pos.move_speed;
	}
}

void		rot_right_cam(t_img *im)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = im->pos.dir_x;
	old_plane_x = im->pos.plane_x;
	im->pos.dir_x = im->pos.dir_x *
		cos(-im->pos.rot_speed) - im->pos.dir_y * sin(-im->pos.rot_speed);
	im->pos.dir_y = old_dir_x * sin(-im->pos.rot_speed) +
		im->pos.dir_y * cos(-im->pos.rot_speed);
	im->pos.plane_x = im->pos.plane_x * cos(-im->pos.rot_speed) -
		im->pos.plane_y * sin(-im->pos.rot_speed);
	im->pos.plane_y = old_plane_x * sin(-im->pos.rot_speed) +
		im->pos.plane_y * cos(-im->pos.rot_speed);
}

void		rot_left_cam(t_img *im)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = im->pos.dir_x;
	old_plane_x = im->pos.plane_x;
	im->pos.dir_x = im->pos.dir_x * cos(im->pos.rot_speed) -
		im->pos.dir_y * sin(im->pos.rot_speed);
	im->pos.dir_y = old_dir_x * sin(im->pos.rot_speed) +
		im->pos.dir_y * cos(im->pos.rot_speed);
	im->pos.plane_x = im->pos.plane_x * cos(im->pos.rot_speed) -
		im->pos.plane_y * sin(im->pos.rot_speed);
	im->pos.plane_y = old_plane_x * sin(im->pos.rot_speed) +
		im->pos.plane_y * cos(im->pos.rot_speed);
}
