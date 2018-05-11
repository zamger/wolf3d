/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:01:28 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/12 13:01:30 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include <time.h>
# include "math.h"

# define W 1200
# define H 800
# define H_W W/2
# define H_H H/2

typedef struct	s_color
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;

}				t_color;

typedef struct	s_col_y
{
	int		x;
	int		begin_y;
	int		end_y;
	t_color col;
	int		map_x;
	int		map_y;
	t_color col_ceiling;
	t_color col_floor;
	
}				t_col_y;

typedef struct	s_var_pos
{

	double	camera_x;
	double	ray_pos_x; 
	double	ray_pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int 	line_height;

}				t_var_pos;

typedef struct  s_pos //position in space
{
	double		pos_x;
	double		pos_y;  //x and y start position
	double		dir_x;
	double		dir_y; //initial direction vector
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	t_var_pos	var_pos;

}				t_pos;

typedef struct s_time
{
	double	time; //time of current frame
  	double	old_time;
  	double	frame_time;
}				t_time;


typedef struct	s_img
{
	void		*mlx;
	void		*win;
	char		*p;
	void		*image;
	t_col_y		col_y;
	t_pos		pos;
	t_time		time;
	int			**world_map;
	int			prev_pos_mouse;
	int			max_x;
	int			max_y;
	int			flag_m;
	int			speed;
}				t_img;

int			ft_mouse_exit(void);
int			my_key_funct(int keycode, t_img *im);
void		make_image(t_img *im);
int			ft_draw(t_img *im);
int			put_pixl(t_img *im);
void		forward_cam(t_img *im);
void		back_cam(t_img *im);
void		rot_right_cam(t_img *im);
void		rot_left_cam(t_img *im);
void		str_cam(t_img *im, char ch);
int			mouse_contr(int x, int y, t_img *im);
void		ft_error(int a);
void		arr_create(t_img *im, const int fd);
void		calc_lenght_ray(t_img *im);
void		cyrcl_dist(t_img *im);
void		calc_dist_on_cam(t_img *im);
void		calc_start_end_strip(t_img *im);
void		calc_fil_pict(t_img *im);
void		menu(t_img *im);

#endif
