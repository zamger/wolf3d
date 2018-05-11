/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_contr_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 18:17:12 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/14 18:17:13 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	mouse_contr(int x, int y, t_img *im)
{
	im->pos.rot_speed = im->time.frame_time * im->speed / 3.0;
		if (x < im->prev_pos_mouse)
			rot_left_cam(im);
		else if (x > im->prev_pos_mouse)
			rot_right_cam(im);
		y = 0;
		im->prev_pos_mouse = x;
	return (0);
}
