/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 11:00:19 by ayundina      #+#    #+#                 */
/*   Updated: 2019/06/25 11:00:23 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct			s_path
{
	int					finish_row;
	int					finish_col;
	int					start_row;
	int					start_col;
}						t_path;

typedef struct			s_set
{
	int					f;
	int					g;
	int					h;
	int					row;
	int					col;
	bool				finish_blocked;
	struct s_set		*parent;
	struct s_set		*next;
}						t_set;

typedef struct			s_player
{
	char				enemy;
	char				me;
	int					row_start_en;
	int					col_start_en;
	int					row_start_me;
	int					col_start_me;
}						t_player;

typedef struct			s_piece
{
	char				*piece;
	int					row_offset;
	int					col_offset;
	int					rows;
	int					cols;
}						t_piece;

typedef struct			s_map
{
	char				*map;
	int					rows;
	int					cols;
}						t_map;

typedef struct			s_game
{
	t_map				*map;
	t_piece				*piece;
	t_player			*player;
	t_path				*path_mid;
	t_path				*path_hor;
	t_path				*path_ver;
	t_set				*open_set;
	t_set				*closed_mid_set;
	t_set				*closed_hor_set;
	t_set				*closed_ver_set;
}						t_game;

/*
**						ft_map.c
*/

int						ft_create_map(t_map *map);
int						ft_update_map(t_game *gm, char *line);

/*
**						ft_piece.c
*/

int						ft_get_piece(t_piece *piece);

/*
**						ft_fight.c
*/

void					ft_reverse_set(t_set **head);
int						ft_fight_loop(t_game *gm);

/*
**						ft_set.c
*/

void					ft_push(t_set *module, t_set **set);
void					ft_pop(int row, int col, t_set **set);
t_set					*ft_create_module(int row, int col, t_set *parent);
int						ft_is_in_set(int row, int col, t_set *set);
void					ft_del_set(t_set **set);

/*
**						ft_check_n_print.c
*/

int						ft_check_and_print(t_game *gm, int row_start,
											int col_start);
int						ft_valid_move(t_game *gm, int r, int c, int i);
int						ft_print_best_set(t_set **set, t_piece *piece);

/*
**						ft_fill_gaps.c
*/

int						ft_fill_gaps(t_game *gm, int r, int c);

/*
**						ft_reached.c
*/

int						ft_reached_col(t_map *map, char player, int c);
int						ft_reached_row(t_map *map, char player, int r);

/*
**						ft_path.c
*/

void					ft_key_path_points(t_game *gm);
int						ft_what_the_path(t_game *gm, t_path *path,
											t_set **closed_set);
int						ft_is_closest(t_set *set_node, t_set *set);
int						ft_found_pattern_four(t_map *map, t_player *player,
												int r, int c);
int						ft_found_pattern_three(t_map *map, t_player *player,
												int r, int c);

/*
**						ft_starting.c
*/

void					ft_starting_mid_set(t_game *gm);
void					ft_starting_hor_ver_set(t_game *gm);
void					ft_find_starting_point(t_game *gm, int *row, int *col);
void					ft_row_col_to_start(int *row, int *col,
											t_set *closed_set, t_map *map);
t_set					*ft_last_node(t_set *set);

/*
**						ft_move_on_path.c
*/

int						ft_move_to_mid(t_game *gm);
int						ft_move_hor(t_game *gm);
int						ft_move_ver(t_game *gm);

/*
**						ft_move_random.c
*/

int						ft_enemy_corner_placement(t_game *gm);
int						ft_random_placement(t_game *gm);
int						ft_next_to_enemy(t_game *gm);

/*
**						ft_placement.c
*/

int						ft_find_best_placement(t_game *gm, t_path *path,
												t_set *closed_set);

/*
**						ft_evaluate.c
*/

void					ft_evaluate_placement(t_set *set, t_path *path);
void					ft_evaluate_push_pop(t_set *tmp_set, t_path *path,
												t_set **open_set);
void					ft_evaluate_set(t_set *set, t_path *path,
										t_set *parent);

/*
**						ft_enemy_corner.c
*/

int						ft_enemy_corner(int r, int c, t_game *gm);

/*
**						ft_neighbours.c
*/

void					ft_find_neighbours(t_game *gm, t_set *cur, t_path *path,
											t_set *cl_set);
int						ft_neighbour_is_a_char(char a_char, t_map *map, int r,
												int c);

/*
**						ft_invalid_path_check.c
*/

int						ft_path_invalid(t_game *gm, t_path *path,
										t_set *closed_set);
void					ft_finish_invalid(t_game *gm, t_path *path);

#endif
