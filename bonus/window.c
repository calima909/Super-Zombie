/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:12:36 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:46:19 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	free_me2(t_prg *prg)
{
	mlx_destroy_image(prg->mlx, prg->wall.ref);
	mlx_destroy_image(prg->mlx, prg->floor.ref);
	mlx_destroy_image(prg->mlx, prg->exit1.ref);
	mlx_destroy_image(prg->mlx, prg->coin.ref);
	mlx_destroy_image(prg->mlx, prg->enemy.ref);
	mlx_destroy_image(prg->mlx, prg->sprite.ref);
}

void	free_me(t_prg *prg)
{
	int	i;

	i = 0;
	while (prg->map[i])
	{
		free(prg->map[i]);
		free(prg->map2[i]);
		i++;
	}
	free(prg->map);
	free(prg->map2);
	free(prg->map_path);
	free_me2(prg);
}

int	ft_quit(t_prg *prg)
{
	free_me(prg);
	mlx_destroy_window(prg->mlx, prg->window.ref);
	mlx_destroy_display(prg->mlx);
	free(prg->mlx);
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
