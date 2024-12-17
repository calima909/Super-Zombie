/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:50:01 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:42:41 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	map_checker(t_prg *prg)
{
	int	len;
	int	x;
	int	y;

	x = -1;
	y = 0;
	len = ft_strlen (prg->map[0]);
	map_checker5(prg, x, y, len);
	map_checker4(prg);
}

void	map_checker2(t_prg *prg)
{
	int	len;
	int	i;
	int	lines;

	i = 0;
	len = (ft_strlen (prg->map[0]) - 2);
	lines = count_lines("map.ber");
	lines--;
	while (prg->map[0][i] && i < len && prg->map[0][i] != '\n')
	{
		if (prg->map[0][i] != '1')
		{
			ft_putstr("mappa non valida, mancano muri nella prima riga\n");
			ft_myfree(prg);
		}
		i++;
	}
	map_checker6(prg, lines);
	map_checker3(prg);
}

void	fill(t_prg *prg, int x, int y)
{
	if (prg->map2[x][y] == 'E')
		prg->flag4 = 1;
	else if (prg->map2[x][y] == 'C')
		prg->flag5++;
	prg->map2[x][y] = '1';
	if (prg->map2[x][y - 1] != '1')
		fill(prg, x, (y - 1));
	if (prg->map2[x - 1][y] != '1')
		fill(prg, (x - 1), y);
	if (prg->map2[x][y + 1] != '1')
		fill(prg, x, (y + 1));
	if (prg->map2[x + 1][y] != '1')
		fill(prg, (x + 1), y);
}

void	path_checker(t_prg *prg)
{
	prg->vector.x = 0;
	while (prg->map2[prg->vector.x])
	{
		prg->vector.y = 0;
		while (prg->map2[prg->vector.x][prg->vector.y])
		{
			if (prg->map2[prg->vector.x][prg->vector.y] == 'P')
			{
				fill(prg, prg->vector.x, prg->vector.y);
				if (prg->flag4 == 0)
				{
					ft_putstr("mappa non valida, nessuna uscita accessibile\n");
					ft_myfree(prg);
				}
			}
			prg->vector.y++;
		}
		prg->vector.x++;
	}
	return ;
}

void	format_checker(char *path, t_prg *prg)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (path[i])
		i++;
	i--;
	if (path[i] != 'r')
		flag = 1;
	i--;
	if (path[i] != 'e')
		flag = 1;
	i--;
	if (path[i] != 'b')
		flag = 1;
	if (flag == 1)
	{
		ft_putstr("formato non valido\n");
		ft_quit(prg);
	}
}
