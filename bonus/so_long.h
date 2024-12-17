/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:42:43 by fchiocci          #+#    #+#             */
/*   Updated: 2023/03/27 17:45:35 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10000
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_prg {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	vector;
	char		**map;
	char		**map2;
	char		*map_path;
	t_image		player;
	t_image		wall;
	t_image		floor;
	t_image		exit1;
	t_image		exit2;
	t_image		exit_coord;
	t_image		coin;
	t_image		enemystart;
	t_image		enemy;
	int			flag;
	int			flag2;
	int			flag3;
	int			flag4;
	int			flag5;
	int			flag6;
	int			flag7;
	int			flag8;
	int			count;
	int			coll_count;
	int			coll_taked;
	char		*moves;
	int			movescount;
}				t_prg;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_input(int key, t_prg *prg);
int			ft_update(t_prg *prg);
int			count_lines(char *file);
void		map_reader(char *file, t_prg *prg);
void		map_checker(t_prg *prg);
void		map_checker3(t_prg *prg);
void		map_checker2(t_prg *prg);
void		map_checker4(t_prg *prg);
void		map_checker5(t_prg *prg, int x, int y, int len);
void		map_checker6(t_prg *prg, int lines);
void		path_checker(t_prg *prg);
void		fill(t_prg *prg, int x, int y);
void		format_checker(char *path, t_prg *prg);
int			map_generator(t_prg *prg);
void		gen_wall(t_prg *prg);
void		gen_floor(t_prg *prg);
void		gen_player(t_prg *prg);
void		gen_coin(t_prg *prg);
void		gen_enemy(t_prg *prg);
void		gen_exit1(t_prg *prg);
void		enemy(t_prg *prg);
char		*ft_strdup(char *s);
char		*ft_itoa(int n);
int			ft_intlen(int n);
void		enemy_attack(t_prg *prg);
void		open_door(t_prg *prg);
void		check_win(t_prg *prg);
void		map_generator2(t_prg *prg);
void		map_generator3(t_prg *prg);
void		map_generator4(t_prg *prg, int x, int y);
void		helpmain(t_prg *prg, char **av);
void		ft_putchar(int c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int			ft_quit(t_prg *prg);
void		free_me(t_prg *prg);
void		free_me2(t_prg *prg);
void		ft_myfree(t_prg *prg);

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_R 114
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
#endif
