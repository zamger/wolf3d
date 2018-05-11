/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:35:26 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/12 12:35:28 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_str(t_img *im)
{
	im->pos.pos_x = 2;
	im->pos.pos_y = 2;
	im->pos.dir_x = -1;
	im->pos.dir_y = 0;
	im->pos.plane_x = 0;
	im->pos.plane_y = 0.66;
	im->time.time = clock();
	im->time.old_time = 0;
	im->col_y.col_ceiling.red = 150;
	im->col_y.col_ceiling.green = 50;
	im->col_y.col_ceiling.blue = 10;
	im->col_y.col_floor.red = 50;
	im->col_y.col_floor.green = 50;
	im->col_y.col_floor.blue = 100;
	im->prev_pos_mouse = H_W;
	im->flag_m = 0;
	im->speed = 10;
}

void		init_cyrcl(t_img *im)
{
	im->pos.var_pos.camera_x = 2 * im->col_y.x / (double)W - 1;
	im->pos.var_pos.ray_pos_x = im->pos.pos_x;
	im->pos.var_pos.ray_pos_y = im->pos.pos_y;
	im->col_y.map_x = im->pos.var_pos.ray_pos_x;
	im->col_y.map_y = im->pos.var_pos.ray_pos_y;
	im->pos.var_pos.ray_dir_x = im->pos.dir_x + im->pos.plane_x *
		im->pos.var_pos.camera_x;
	im->pos.var_pos.ray_dir_y = im->pos.dir_y + im->pos.plane_y *
		im->pos.var_pos.camera_x;
	im->pos.var_pos.delta_dist_x = sqrt(1 +
		(im->pos.var_pos.ray_dir_y * im->pos.var_pos.ray_dir_y) /
			(im->pos.var_pos.ray_dir_x * im->pos.var_pos.ray_dir_x));
	im->pos.var_pos.delta_dist_y = sqrt(1 +
		(im->pos.var_pos.ray_dir_x * im->pos.var_pos.ray_dir_x) /
			(im->pos.var_pos.ray_dir_y * im->pos.var_pos.ray_dir_y));
	im->pos.var_pos.hit = 0;
}

void		calc_fil_pict(t_img *im)
{
	im->col_y.x = 0;
	while (im->col_y.x < W)
	{
		init_cyrcl(im);
		calc_lenght_ray(im);
		cyrcl_dist(im);
		calc_dist_on_cam(im);
		im->pos.var_pos.line_height = (int)(H /
			im->pos.var_pos.perp_wall_dist);
		calc_start_end_strip(im);
		put_pixl(im);
		im->col_y.x += 1;
	}
	im->time.old_time = im->time.time;
	im->time.time = clock();
	im->time.frame_time = ((im->time.time - im->time.old_time) / CLOCKS_PER_SEC);
}

int			val_map(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_error(1);
	fd = 0;
	if (ft_strequ(argv[1], "map1"))
	{
		fd = open("map1.map", O_RDONLY);
		system("afplay ./map1.mp3&");
	}
	else if (ft_strequ(argv[1], "map2"))
	{
		fd = open("map2.map", O_RDONLY);
		system("afplay ./map2.mp3&");
	}
	else
		ft_error(5);
	if (fd <= 0)
		ft_error(2);
	return (fd);
}

int			main(int argc, char **argv)
{
	t_img	im;

	arr_create(&im, val_map(argc, argv));
	im.mlx = mlx_init();
	im.win = mlx_new_window(im.mlx, W, H, "wolf3d");
	init_str(&im);
	ft_draw(&im);
	mlx_hook(im.win, 17, 0, ft_mouse_exit, 0);
	mlx_hook(im.win, 2, 0, &my_key_funct, &im);
	mlx_hook(im.win, 6, 0, &mouse_contr, &im);
	mlx_loop_hook(im.mlx, &ft_draw, &im);
	mlx_loop(im.mlx);
	return (0);
}
