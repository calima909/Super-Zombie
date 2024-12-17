/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:00:23 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:48:45 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		i = 6;
	}
	else
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}	
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	map_checker3(t_prg *prg)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(prg->map[0]);
	i = -1;
	len -= 2;
	while (prg->map[++i])
	{
		if (prg->map[i][0] != '1')
		{
			ft_putstr("mancano muri nella prima colonna\n");
			ft_myfree(prg);
		}
	}
	j = i;
	i = -1;
	while (++i < j && prg->map[i][len])
	{
		if (prg->map[i][len] != '1')
		{
			ft_putstr("mancano muri nell'ultima colonna\n");
			ft_myfree(prg);
		}
	}
}

void	map_checker6(t_prg *prg, int lines)
{
	int	i;

	i = 0;
	while (prg->map[lines][i] != '\n')
	{
		if (prg->map[lines][i] != '1')
		{
			ft_putstr("mappa non valida, mancano muri nell'ultima riga\n");
			ft_myfree(prg);
		}
		i++;
	}
}
