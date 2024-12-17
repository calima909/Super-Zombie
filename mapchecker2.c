/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:18:00 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:19:46 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_myfree(t_prg *prg)
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
	exit(1);
}

void	map_checker4(t_prg *prg)
{
	if (prg->flag8 != 1)
	{
		ft_putstr("troppi o nessun player\n");
		ft_myfree(prg);
	}
	if (prg->flag7 != 1)
	{
		ft_putstr("troppe o nessuna uscita\n");
		ft_myfree(prg);
	}	
	if (prg->flag6 < 1)
	{
		ft_putstr("troppi pochi collezionabili\n");
		ft_myfree(prg);
	}
}

void	map_checker5(t_prg *prg, int x, int y, int len)
{
	while (prg->map[++x])
	{
		if (ft_strlen(prg->map[x]) != len)
		{
			ft_putstr("mappa non valida\n");
			ft_myfree(prg);
		}
		y = 0;
		while (prg->map[x][++y])
		{
			if (prg->map[x][y] == 'P')
				prg->flag8 += 1;
			else if (prg->map[x][y] == 'E')
				prg->flag7 += 1;
			else if (prg->map[x][y] == 'C')
				prg->flag6 += 1;
			else if (prg->map[x][y] && prg->map[x][y] != 'P' && prg->map[x][y]
			!='E' && prg->map[x][y] != 'C' && prg->map[x][y] != 'X' && prg->map
			[x][y] != '0' && prg->map[x][y] != '1' && prg->map[x][y] != '\n')
			{
				ft_putstr("Caratteri nella mappa non validi\n");
				ft_myfree(prg);
			}
		}
	}
}
