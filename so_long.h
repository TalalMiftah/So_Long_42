/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:24:56 by tmiftah           #+#    #+#             */
/*   Updated: 2023/01/21 21:50:12 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_list
{
	int		height;
	int		width;
	char	**map;
	int		i;
	int		j;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		moves;
	int		p;
	int		c;
	int		e;
	int		skipx;
	int		skipy;
	void	*mlx;
	void	*img;
	void	*animation;
	void	*win;
	void	*player;
	void	*col;
	void	*exit;
	void	*wall;
	void	*grass;
	int		move;
	int		n;
}			t_list;

void	extention_check(char *name);
void	map_height(char *name, t_list *so_long);
void	read_map(char *name, t_list *so_long);
void	map_valid(char *name, t_list *so_long);
void	map_check(t_list *so_long);
void	width_check(t_list *so_long);
void	frame_check(t_list *so_long);
void	content_check(t_list *so_long);
void	backtracking(t_list *so_long);
int		position(char **map, int i, int j);
char	*next_ryhme(char *str);
char	*ft_rhyme(char *s);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_read(int fd, char *s);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);
int		ft_strcmp(char *c1, char *c2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(const char *s);
int		ft_printf(const char *s, ...);
char	*ft_strdup(char *c1);
int		print_map(t_list *so_long);
void	printing(t_list *so_long);
void	destroy(t_list *so_long);
void	map_var(t_list *so_long, char c);
int		move(int key, t_list *so_long);
void	right(t_list *so_long);
void	down(t_list *so_long);
void	left(t_list *so_long);
void	up(t_list *so_long);
char	*ft_itoa(int n);
int		closewin(t_list *so_long);
int		animation(t_list *so_long);
void	you_won(t_list *so_long);
void	game_ended(t_list *so_long);
void	print_grass(t_list *so_long);
void	backtracking_col(t_list *so_long);
int		position1(char **map, int i, int j);
int		count_c(char **c);

#endif
