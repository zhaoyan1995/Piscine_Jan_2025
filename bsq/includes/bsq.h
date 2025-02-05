/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:38:03 by hguo              #+#    #+#             */
/*   Updated: 2025/02/05 18:48:25 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_grid
{
	int	x;
	int	y;
	int	size;
}	t_grid;

typedef struct s_old
{
	int		row;
	int		col;
	char	**map;
	char	vide;
	char	obstacle;
	char	plein;
}	t_old;

typedef struct s_map
{
	int		row;
	int		col;
	int		**map;
	t_grid	grid;
}	t_map;

//write_to_file.c
int		write_to_file(const char *filename);

//check_solution.c
void	check_solution(int file, char *argv);

//check_line_col_oldmap.c
char	*save_input(int file, char *argv);
char	*skip_first_line(char *buffer2);
int		count_col_first(char *buffer2);
int		count_line(char *buffer2);
int		check_nbr_line(char *buffer2, int nb_line);

//check_char_old_map.c
int		check_repete(char *buffer2);
int		check_char2(char c, char obstacle, char vide);
int		check_char(char *buffer2);
int		check_map(char *buffer2);

//count_col.c
int		count_col(char *buffer2);

//load_oldmap.c
void	free_rows(char **map, int row);
char	**save_input_map(char *buffer2, int row, int col, int i);
t_old	*save_input2(char *buffer2, int row, int col);

//basic1.c
int		ft_min(int a, int b, int c);
void	free_grid(int **grid, int row);
void	free_old(t_old *old);
void	free_print(t_map *print);
void	ft_putchar(char c);

//find_fill.c
int		convert_map(char c, char obstacle);
int		**copy_grid(t_old old);
int		**calcul_size(t_old old, int **new);
t_grid	find_grid(int **new, t_old old);
void	fill_grid(int **map, t_grid grid);

//prep_map.c
int		**alloc_map_array(int row, int col);
t_map	*init_map(t_old old);
void	fill_digitmap(t_map *print, t_old old);
void	prep_map(t_map *print, t_old old);

//print_map.c
void	print_cell(t_map *print, t_old old, int i, int j);
void	print_map(t_map *print, t_old old);

#endif
