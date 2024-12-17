/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:12:28 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:20:02 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <string.h>

void	helpmain(t_prg *prg, char **av)
{
	prg->flag = 0;
	prg->flag2 = 0;
	prg->flag3 = 0;
	prg->flag4 = 0;
	prg->flag5 = 0;
	prg->flag6 = 0;
	prg->flag7 = 0;
	prg->flag8 = 0;
	prg->coll_taked = 0;
	prg->count = 0;
	prg->coll_count = 0;
	prg->movescount = 0;
	prg->moves = NULL;
	prg->map_path = ft_strdup(av[1]);
	map_reader(av[1], prg);
	format_checker(prg->map_path, prg);
	map_checker(prg);
	map_checker2(prg);
	path_checker(prg);
}

void	helpmain2(t_prg *prg, char **av)
{
	prg->window = ft_new_window(prg->mlx, (ft_strlen (prg->map[0]) - 1) * 50,
			(count_lines(av[1])) * 50, "so_long by fchiocci");
	prg->sprite = ft_new_sprite(prg->mlx, "sprite/zombi_sfondo.xpm");
	prg->floor = ft_new_sprite(prg->mlx, "sprite/wall.xpm");
	prg->wall = ft_new_sprite(prg->mlx, "sprite/floor.xpm");
	prg->exit1 = ft_new_sprite(prg->mlx, "sprite/exit1.xpm");
	prg->coin = ft_new_sprite(prg->mlx, "sprite/coin_sfondo.xpm");
	prg->enemy = ft_new_sprite(prg->mlx, "sprite/mario.xpm");
}

int	main(int ac, char **av)
{
	t_prg	prg;

	if (ac != 2)
	{
		ft_putstr("numero di argomenti non valido\n");
		exit(1);
	}
	helpmain(&prg, av);
	prg.mlx = mlx_init();
	helpmain2(&prg, av);
	map_generator(&prg);
	mlx_string_put(prg.mlx, prg.window.ref, 12, 25, 16777216, "0");
	prg.coll_count = prg.count;
	mlx_key_hook(prg.window.ref, *ft_input, &prg);
	if (prg.coll_count != prg.flag5)
	{
		ft_putstr("mappa non valida, collezionabile non accessibile\n");
		ft_quit(&prg);
	}
	mlx_loop_hook(prg.mlx, ft_update, &prg);
	mlx_hook(prg.window.ref, 17, 0, ft_quit, &prg);
	mlx_loop(prg.mlx);
	mlx_destroy_display(prg.mlx);
}
