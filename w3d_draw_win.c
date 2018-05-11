/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_draw_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:48:27 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/12 17:48:27 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		make_image(t_img *im)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	im->image = mlx_new_image(im->mlx, W, H);
	im->p = mlx_get_data_addr(im->image, &bits_per_pixel,
		&size_line, &endian);
}

t_color		color_wall(int num_wall)
{
	t_color color;

	color.red = 0;
	color.green = 0;
	color.blue = 10;
	if (num_wall == 1)
		color.red = 255;
	else if (num_wall == 2)
		color.green = 255;
	else if (num_wall == 3)
	{
		color.green = 255;
		color.blue = 255;
	}
	else if (num_wall == 4)
		color.blue = 255;
	else if (num_wall == 5)
	{
		color.red = 255;
		color.blue = 255;
	}
	return (color);
}

void		filling_pix(t_img *im, int begin_point,
		int end_point, t_color color)
{
	while (begin_point < end_point)
	{
		im->p[(int)((im->col_y.x) * 4) +
			(int)(begin_point * W * 4) + 2] = color.red;
		im->p[(int)((im->col_y.x) * 4) +
			(int)(begin_point * W * 4) + 1] = color.green;
		im->p[(int)((im->col_y.x) * 4) +
			(int)(begin_point * W * 4)] = color.blue;
		begin_point++;
	}
}

int			put_pixl(t_img *im)
{
	int y;

	y = 0;
	im->col_y.col = color_wall(im->world_map[im->col_y.map_y]
		[im->col_y.map_x]);
	if (im->pos.var_pos.side == 1)
	{
		im->col_y.col.red /= 2;
		im->col_y.col.green /= 2;
		im->col_y.col.blue /= 2;
	}
	filling_pix(im, 0, im->col_y.begin_y, im->col_y.col_ceiling);
	filling_pix(im, im->col_y.begin_y, im->col_y.end_y, im->col_y.col);
	filling_pix(im, im->col_y.end_y, H, im->col_y.col_floor);
	return (0);
}

int			ft_draw(t_img *im)
{
	make_image(im);
	calc_fil_pict(im);
	mlx_put_image_to_window(im->mlx, im->win, im->image, 0, 0);
	menu(im);
	mlx_destroy_image(im->mlx, im->image);
	return (1);
}
