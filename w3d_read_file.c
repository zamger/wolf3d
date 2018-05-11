/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 12:22:52 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/15 12:22:52 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(int a)
{
	if (a == 1)
			ft_putendl("too many file or nothing file!");
	if (a == 2)
	{
		ft_putendl("can't open file");
		system("killall afplay");
	}
	if (a == 3)
		ft_putendl("not valid file");
	if (a == 4)
		ft_putendl("empty file!");
	if (a == 5)
		ft_putendl("write map1 or map2!");	
	exit(0);
}

char		*ft_strjoin_mod(char *s1, char *s2)
{
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	str = ft_strnew(len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_strcat(str, s1);
	ft_strcat(str + len, s2);
	free(s1);
	free(s2);
	return (str);
}

void		arr_counter(t_img *im, char *arr)
{
	int		x;
	int		temp_x;
	int		i;
	int		y;

	y = 0;
	i = 0;
	temp_x = 0;
	while (arr[i])
	{
		x = 0;
		while (arr[i] != '\n' && arr[i])
		{
			(arr[i + 1] == ' ' && arr[i] != ' ') ? x++ : 0;
			i++;
		}
		(arr[i - 1] != ' ') ? x++ : 0;
		if (temp_x > 0)
			(x != temp_x) ? ft_error(3) : 0;
		temp_x = x;
		y++;
		i++;
	}
	im->max_x = x;
	im->max_y = y;
}

char		*read_file(const int fd, t_img *im)
{
	char	line[100001];
	char	*return_arr;
	int		buff;

	return_arr = ft_strnew(0);
	while ((buff = read(fd, line, 100000)) > 0)
	{
		line[buff] = '\0';
		return_arr = ft_strjoin_mod(return_arr, ft_strdup(line));
	}
	arr_counter(im, return_arr);
	return (return_arr);
}

void		arr_create(t_img *im, const int fd)
{
	char	*arr;
	int		x;
	int		y;
	int		a;

	a = 0;
	y = 0;
	arr = read_file(fd, im);
	im->world_map = (int**)malloc(sizeof(int*) * im->max_y);
	while (a < im->max_y)
	{
		im->world_map[a] = (int*)malloc(sizeof(int) * im->max_x);
		a++;
	}
	while (y < im->max_y)
	{
		x = 0;
		while (x < im->max_x)
		{
			im->world_map[y][x] = ft_atoi(&arr[2 * (y * im->max_x + x)]);
			x++;
		}
		y++;
	}
	free(arr);
}
