/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_contr_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:38:07 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/12 17:38:07 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_mouse_exit(void)
{
	system("killall afplay");
	exit(0);
}

void		menu(t_img *im)
{
	if ((im->flag_m % 2))
	{
		mlx_string_put(im->mlx, im->win, 10, 10,
			0xFF00FF, "MENU");
		mlx_string_put(im->mlx, im->win, 10, 30,
			0xFFFF00, "MOVE KEY: w s (forw back) q e(rot) a d(str)");
		mlx_string_put(im->mlx, im->win, 10, 50,
			0x6060FF, "FIRE KEY: f");
		mlx_string_put(im->mlx, im->win, 10, 70,
			0xFFFFFF, "SPEED KEY:  + -");
		mlx_string_put(im->mlx, im->win, 10, 90,
			0xFF0FFF, "FPS:");
		mlx_string_put(im->mlx, im->win, 50, 90,
			0xFF0FFF, ft_itoa((int)1/im->time.frame_time));
		
	}
}

int			my_key_funct(int keycode, t_img *im)
{
	im->pos.move_speed = im->time.frame_time * im->speed;
	im->pos.rot_speed = im->time.frame_time * im->speed / 3.0;
	if (keycode == 53)
	{
		system("killall afplay");
		exit(0);
	}
	keycode == 13 ? forward_cam(im) : 0;
	keycode == 1 ? back_cam(im) : 0;
	keycode == 14 ? rot_right_cam(im) : 0;
	keycode == 12 ? rot_left_cam(im) : 0;
	keycode == 2 ? str_cam(im, 'r') : 0;
	keycode == 0 ? str_cam(im, 'l') : 0;
	keycode == 3 ? system("afplay ./gun1.mp3 -t 1 &") : 0;
	keycode == 46 ? im->flag_m += 1 : 0;
	keycode == 78 ? im->speed -= 5 : 0;
	keycode == 69 ? im->speed += 5 : 0;
	im->speed < 0 ? im->speed = 1 : 0;
	im->speed > 30 ? im->speed = 60 : 0;
	return (0);
}
