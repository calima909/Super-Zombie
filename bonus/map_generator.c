/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:02:25 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 15:42:26 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	gen_enemy(t_prg *prg)
{
	prg->enemy.size.x = prg->enemystart.size.x;
	prg->enemy.size.y = prg->enemystart.size.y;
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->enemy.ref, prg->enemy.size.x, prg->enemy.size.y);
	prg->map[prg->enemy.size.y / 50][prg->enemy.size.x / 50] = '0';
}

int	map_generator(t_prg *prg)
{
	int	x;
	int	y;

	map_generator2(prg);
	x = -1;
	while (prg->map[++x])
	{
		y = -1;
		while (prg->map[x][++y])
		{
			map_generator4(prg, x, y);
		}
		map_generator3(prg);
	}
	return (0);
}

void	map_generator2(t_prg *prg)
{
	prg->wall.size.x = 0;
	prg->wall.size.y = 0;
	prg->floor.size.x = 0;
	prg->floor.size.y = 0;
	prg->sprite.size.x = 0;
	prg->sprite.size.y = 0;
	prg->exit1.size.x = 0;
	prg->exit1.size.y = 0;
	prg->coin.size.x = 0;
	prg->coin.size.y = 0;
	prg->enemystart.size.x = 0;
	prg->enemystart.size.y = 0;
}

void	map_generator3(t_prg *prg)
{
	prg->wall.size.x = 0;
	prg->wall.size.y += 50;
	prg->floor.size.x = 0;
	prg->floor.size.y += 50;
	prg->sprite.size.x = 0;
	prg->sprite.size.y += 50;
	prg->exit1.size.x = 0;
	prg->exit1.size.y += 50;
	prg->coin.size.x = 0;
	prg->coin.size.y += 50;
	prg->enemystart.size.x = 0;
	prg->enemystart.size.y += 50;
}

void	map_generator4(t_prg *prg, int x, int y)
{
	if (prg->map[x][y] == '1')
		gen_wall(prg);
	if (prg->map[x][y] == 'P' && prg->flag2 == 0)
		gen_player(prg);
	else if (prg->map[x][y] == '0')
		gen_floor(prg);
	else if (prg->map[x][y] == 'X')
		gen_enemy(prg);
	else if (prg->map[x][y] == 'E')
		gen_exit1(prg);
	else if (prg->map[x][y] == 'C')
		gen_coin(prg);
	prg->wall.size.x += 50;
	prg->floor.size.x += 50;
	prg->sprite.size.x += 50;
	prg->exit1.size.x += 50;
	prg->coin.size.x += 50;
	prg->enemystart.size.x += 50;
}
