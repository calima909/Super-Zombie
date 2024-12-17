/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:12:59 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:06:10 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <string.h>

int	count_lines(char *file)
{
	int		i;
	int		fd;
	int		readcount;
	char	c;

	readcount = 1;
	i = 0;
	fd = open(file, O_RDONLY);
	while (readcount > 0 && fd >= 0)
	{
		readcount = read(fd, &c, 1);
		if (c == '\n' || c == '\0')
			i++;
	}
	close(fd);
	return (i - 1);
}

void	map_reader(char *file, t_prg *prg)
{
	int		b;
	int		count;
	int		fd;

	b = 0;
	count = count_lines(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("file non esistente\n");
		free(prg->map_path);
		exit(0);
	}
	prg->map = (char **) malloc (sizeof(char *) * (count + 1));
	prg->map2 = (char **) malloc (sizeof (char *) * (count + 1));
	while (b < count)
	{
		prg->map[b] = get_next_line(fd);
		prg->map2[b] = ft_strdup(prg->map[b]);
		b++;
	}
	prg->map[b] = NULL;
	prg->map2[b] = NULL;
	close(fd);
}
