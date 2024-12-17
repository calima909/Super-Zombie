/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:12:31 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/22 14:50:55 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.ref = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}
