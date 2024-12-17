/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:44:18 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/21 17:53:38 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	gen_wall(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->wall.ref, prg->wall.size.x, prg->wall.size.y);
}

void	gen_floor(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->floor.ref, prg->floor.size.x, prg->floor.size.y);
}

void	gen_player(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->floor.ref, prg->sprite.size.x, prg->sprite.size.y);
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->sprite.ref, prg->sprite.size.x, prg->sprite.size.y);
	prg->player.size.x = prg->sprite.size.x;
	prg->player.size.y = prg->sprite.size.y;
	prg->map[prg->sprite.size.y / 50][prg->sprite.size.x / 50] = '0';
	prg->flag2 = 1;
}

void	gen_exit1(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->exit1.ref, prg->exit1.size.x, prg->exit1.size.y);
	prg->exit_coord.size.x = prg->exit1.size.x;
	prg->exit_coord.size.y = prg->exit1.size.y;
}

void	gen_coin(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->window.ref,
		prg->coin.ref, prg->coin.size.x, prg->coin.size.y);
	prg->count += 1;
}
