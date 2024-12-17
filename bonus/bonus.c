/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:45:06 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/24 16:50:31 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy(t_prg *prg)
{
	int	moves;

	moves = rand() % 5;
	if (moves == 1 && prg->map[prg->enemy.size.y / 50]
		[(prg->enemy.size.x / 50) + 1] != '1')
		prg->enemy.size.x += 50;
	else if (moves == 2 && prg->map[prg->enemy.size.y / 50]
		[(prg->enemy.size.x / 50) - 1] != '1')
		prg->enemy.size.x -= 50;
	else if (moves == 3 && prg->map[(prg->enemy.size.y / 50) + 1]
		[prg->enemy.size.x / 50] != '1')
		prg->enemy.size.y += 50;
	else if (moves == 4 && prg->map[(prg->enemy.size.y / 50) - 1]
		[(prg->enemy.size.x / 50)] != '1')
		prg->enemy.size.y -= 50;
}

void	enemy_attack(t_prg *prg)
{
	if ((prg->player.size.x == prg->enemy.size.x)
		&& (prg->player.size.y == prg->enemy.size.y))
	{
		ft_putstr("Hai perso\n");
		ft_quit(prg);
	}
}

void	open_door(t_prg *prg)
{
	if (prg->coll_count == prg->coll_taked)
	{		
		mlx_destroy_image(prg->mlx, prg->exit1.ref);
		prg->exit1 = ft_new_sprite(prg->mlx, "sprite/exit2.xpm");
	}
}

void	check_win(t_prg *prg)
{
	if ((prg->player.size.x == prg->exit_coord.size.x)
		&& (prg->player.size.y == prg->exit_coord.size.y)
		&& (prg->coll_count == prg->coll_taked))
	{
		ft_putstr("Hai vinto\n");
		ft_quit(prg);
	}
}
