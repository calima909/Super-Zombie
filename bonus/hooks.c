/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:12:33 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/24 18:09:40 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move_player(int key, t_prg *prg)
{
	if (key == 65307)
		ft_quit(prg);
	else if (key == KEY_D && prg->map[prg->player.size.y / 50]
		[(prg->player.size.x / 50) + 1] != '1')
		prg->player.size.x += 50;
	else if (key == KEY_A && prg->map[prg->player.size.y / 50]
		[(prg->player.size.x / 50) - 1] != '1')
		prg->player.size.x -= 50;
	else if (key == KEY_S && prg->map[(prg->player.size.y / 50) + 1]
		[prg->player.size.x / 50] != '1')
		prg->player.size.y += 50;
	else if (key == KEY_W && prg->map[(prg->player.size.y / 50) - 1]
		[prg->player.size.x / 50] != '1')
		prg->player.size.y -= 50;
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		prg->movescount += 1;
	if (prg->map[prg->player.size.y / 50][prg->player.size.x / 50] == 'C'
		|| prg->map[prg->player.size.y / 50][prg->player.size.x / 50] == 'P')
	{
		prg->map[prg->player.size.y / 50][prg->player.size.x / 50] = '0';
		prg->coll_taked += 1;
	}
}

void	update_game(t_prg *prg)
{
	enemy_attack(prg);
	enemy(prg);
	enemy_attack(prg);
	if (prg->map[prg->enemy.size.y / 50][prg->enemy.size.x / 50] &&
		prg->map[prg->enemy.size.y / 50][prg->enemy.size.x / 50] == '0')
		prg->map[prg->enemy.size.y / 50][prg->enemy.size.x / 50] = 'X';
	open_door(prg);
	check_win(prg);
	map_generator(prg);
}

int	ft_input(int key, t_prg *prg)
{
	mlx_clear_window(prg->mlx, prg->window.ref);
	move_player(key, prg);
	update_game(prg);
	ft_putstr("Mosse fatte: ");
	ft_putnbr(prg->movescount);
	prg->moves = ft_itoa(prg->movescount);
	mlx_string_put(prg->mlx, prg->window.ref, 12, 25, 16777216, prg->moves);
	free(prg->moves);
	mlx_put_image_to_window(prg->mlx, prg->window.ref, prg->sprite.ref,
		prg->player.size.x, prg->player.size.y);
	ft_putchar('\n');
	return (0);
}

int	ft_update(t_prg *prg)
{
	static int	frame;

	frame++;
	check_win(prg);
	enemy_attack(prg);
	if (frame == ANIMATION_FRAMES)
		prg->player.size.x += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		prg->player.size.x -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(prg->mlx, prg->window.ref, prg->sprite.ref,
		prg->player.size.x, prg->player.size.y);
	return (0);
}
